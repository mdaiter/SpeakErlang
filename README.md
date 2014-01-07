# ErlangSpeak (ErlSpeak)

ErlangSpeak is an OTP library to allow Erlang users to use Espeak to "speak" through Erlang.

##Getting Started
Two basic steps:
* rebar compile
* cd c_src; make
If there are library linker issues while making the C files, I soft linked my nif header file to /usr/local/include/erlang/erl_nif.h, along with the entire directory of erlang headers.

##Basic Usage
```erlang
application:start(speak).
speak:speak("Default", "hello!").
