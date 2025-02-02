# DynCall Plugify Plugin

The dyncall library encapsulates architecture-, OS- and compiler-specific function call semantics in a virtual bind argument parameters from left to right and then call interface allowing programmers to call C functions in a completely dynamic manner. In other words, instead of calling a function directly, the dyncall library provides a mechanism to push the function parameters manually and to issue the call afterwards.
This means, that a program can determine at runtime what function to call, and what parameters to pass to it. The library is written in C and assembly and provides a very simple C interface to program against.

[dyncall.org](https://dyncall.org/)
