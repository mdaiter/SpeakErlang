{application, speak,
 [
   {description, "An ESpeak binding for Erlang. Tested on Linux. Uses the speak_lib.h API"},
     {vsn, "1"},
       {modules, [
                    speak_app,
                                 speak_sup,
                                              speak
                                                          ]},
                                                            {registered, []},
                                                              {applications, [
                                                                                kernel,
                                                                                                  stdlib
                                                                                                                   ]},
                                                                                                                     {mod, { speak_app, []}},
                                                                                                                       {env, []}
                                                                                                                        ]}.
