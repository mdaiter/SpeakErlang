-module(speak_app).
-behaviour(application).
-export([start/2, stop/1]).


start(__Type, __Args) ->
  speak_sup:start_link().
stop(__State) ->
  ok.
