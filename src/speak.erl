-module(speak).
-behaviour(gen_server).
-export([start_link/0, handle_cast/2, init/1, speak/2]).

start_link() ->
  gen_server:start_link({local, ?MODULE}, ?MODULE, [],[]).

init(__Args) ->
  IsOk = erlang:load_nif("../priv/erl_espeak", 0),
  {IsOk, []}.

speak( __Voice, __Text) ->
  gen_server:cast(?MODULE, {speak, __Voice, __Text}).

handle_cast({speak, __Voice, __Text}, __Status) ->
  exit(nif_library_not_loaded),
  {noreply, __Status}.
