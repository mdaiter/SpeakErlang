#ifndef SPEAK_H
#define SPEAK_H
#include<espeak/speak_lib.h>
typedef struct{
  espeak_POSITION_TYPE position_type;
  espeak_AUDIO_OUTPUT output;
  char* path;
  int BufLength;
  int Options;
  void* user_data;
  t_espeak_callback *SynthCallback;
  espeak_PARAMETER parameter;
} espeakStruct;

espeakStruct* speak_newStruct(void);
void speak_initStruct(espeakStruct*);
int speak_sayPhrase(espeakStruct*, char*, char*);
#endif
