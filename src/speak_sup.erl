-module(speak_sup).
-behaviour(supervisor).
-export([start_link/0, init/1]).

-spec start_link() -> {ok, pid()}.
start_link() ->
  supervisor:start_link({local, ?MODULE}, ?MODULE, []).

init(__Args) ->
  {ok, {{one_for_one, 10, 10},
                 [{speak, {speak, start_link, []},
                              permanent, brutal_kill, worker, [speak]}]}}.
