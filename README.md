# RVALUE REFERENCE
+ To move the object that the `lvalue reference` points to, one can move the object directly 
    - std::move is used to `convert to rvalue reference`, it is exactly equivalent to a *static_cast to an rvalue reference*.
+ A named rvalue is an lvalue as all Named objects are lvalues
+ Rvalue references _can only bind_ to Rvalues

# LVALUE REFERENCE
+ A reference that `binds to an lvalue`, lvalue reference is marked with a single ampersand (*&*).

# std::move()
Returning by *`std::move`* is a commonly known C++ antipattern:

+ it disables (N)RVO ((Named-)Return-Value-Optimization) meaning that copy elision is not happening
+ it makes our code redundant as move will happen even without explicitly calling *`std::move`*

# Compile & Run
```bash
g++ references.cpp -o references ; ./$_
OR
g++ references.cpp -o references ; ./references
```

# References
[Rvalue references in C++](https://medium.com/pranayaggarwal25/rvalue-references-e99dfd3933ff)

[reference-to-const](https://medium.com/@vgasparyan1995/pass-by-value-vs-pass-by-reference-to-const-c-f8944171e3ce)

[Antipattern](https://github.com/m-peko/craft-cpp/blob/master/_posts/2021-09-28-when-is-an-antipattern-not-an-antipattern.md)