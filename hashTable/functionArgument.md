# Function Pointer Summary

## Ordinary pointer

int *ptr;


`ptr` points to an `int`.

## Function pointer

int (*func)(int);


`func` points to a function that accepts an `int` and returns an `int`.

## Function pointer that accepts `int *` and returns `bool`

bool (*function)(int *);


## Creating a function pointer type with `typedef`

typedef bool (*fc)(int *);


Here, `fc` is a type name, not a variable.

## Declaring a variable using the new type

fc function;


Therefore, the following two forms are equivalent:

bool (*function)(int *);


typedef bool (*fc)(int *);
fc function;


## Core difference

Without `typedef`, the variable name is written inside `(*...)`:

bool (*function)(int *);


With `typedef`, the function pointer type can be used like an ordinary type:

fc function;

