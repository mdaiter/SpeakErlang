-module(speak).
-compile(export_all).
-on_load(init/0).

init() ->
  ok = erlang:load_nif("../priv/erl_espeak", 0).

speak( __Voice, __Text) ->
  exit(nif_library_not_loaded).
