#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "speak.h"

espeakStruct* speak_newStruct(void){
  espeakStruct* estruct = malloc(sizeof *estruct);
  return estruct;
}

void speak_initStruct(espeakStruct* estruct){
  estruct->output = AUDIO_OUTPUT_PLAYBACK;
  estruct->path = NULL;
  estruct->BufLength = 500;
  estruct->Options = 0;
}

int speak_sayPhrase(espeakStruct* esp, char* voice, char* phrase){
  unsigned int position=0, end_position=0, flags=espeakCHARS_AUTO, *unique_identifier;
  espeak_SetVoiceByName(voice);
  unsigned int Size = strlen(phrase) + 1;
  printf("Saying '%s' with StrLen %d and unsigned int %d\n", phrase, Size, esp->position_type);
  espeak_Synth(phrase, Size, position, esp->position_type, end_position, flags, unique_identifier, esp->user_data);
  espeak_Synchronize();
  return 0;
}

/*int main(int argc, char* argv[]){
  char Voice[] = {"default"};
  char text[20] = {"Hello, world!"};

  espeakStruct* esp = speak_newStruct();
  speak_initStruct(esp);
  espeak_Initialize(esp->output, esp->BufLength, esp->path, esp->Options);
  speak_sayPhrase(esp, Voice, text);
  speak_sayPhrase(esp, Voice, text);
  free(esp);
  return 0;
}*/
