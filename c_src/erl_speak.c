#include<erlang/erl_nif.h>
#include "speak.h"
#include<string.h>
#define MAXBUFLEN 1024
static ErlNifResourceType *MEM_RESOURCE;

static espeakStruct* esp;

static int on_load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info){
  ErlNifResourceFlags flags = (ErlNifResourceFlags)(ERL_NIF_RT_CREATE);
  if (
       (MEM_RESOURCE = enif_open_resource_type(env, NULL, "mem_resource", NULL, flags, NULL)) == NULL
      ){
    return -1;
  }
  
  espeakStruct* estruct;
  int mem_size = sizeof(espeakStruct);
  estruct = enif_alloc_resource(MEM_RESOURCE, mem_size);
  if (estruct == NULL){
    return enif_make_atom(env, "error");
  }
  speak_initStruct(estruct);
  espeak_Initialize(estruct->output, estruct->BufLength, estruct->path, estruct->Options);
  ERL_NIF_TERM term = enif_make_resource(env, estruct);
  esp = estruct;
  espeak_Initialize(esp->output, esp->BufLength, esp->path, esp->Options);
  return 0;
};

static ERL_NIF_TERM speak(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]){
  if (argc == 2){

    char voice[MAXBUFLEN];
    char text[MAXBUFLEN];
    
    (void)memset(&voice, '\0', sizeof(voice));
    (void)memset(&text, '\0', sizeof(text));

    if(!enif_get_string(env, argv[0], voice, sizeof(voice), ERL_NIF_LATIN1)){
      return enif_make_badarg(env);
    }
    if(!enif_get_string(env, argv[1], text, sizeof(text), ERL_NIF_LATIN1)){
      return enif_make_badarg(env);
    }
    speak_sayPhrase(esp, voice, text);
    return enif_make_atom(env, "ok");
  }
  else{
    return enif_make_badarg(env);
  }
};

static ErlNifFunc nif_funcs[] = {
  {"speak", 2, speak}
};

ERL_NIF_INIT(speak, nif_funcs, on_load, NULL, NULL, NULL);
