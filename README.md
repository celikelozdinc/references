# RVALUE REFERENCE
+ To move the object that the `lvalue reference` points to, one can move the object directly 
    - std::move is used to `convert to rvalue reference`, it is exactly equivalent to a *static_cast to an rvalue reference*.
+ A named rvalue is an lvalue as all Named objects are lvalues
+ Rvalue references _can only bind_ to Rvalues

# LVALUE REFERENCE
+ A reference that `binds to an lvalue`, lvalue reference is marked with a single ampersand (*&*).

# Compile & Run
```bash
g++ references.cpp -o references ; ./$_
OR
g++ references.cpp -o references ; ./references
```

# References
[Rvalue references in C++](https://medium.com/pranayaggarwal25/rvalue-references-e99dfd3933ff)