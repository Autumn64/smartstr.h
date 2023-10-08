# NSSTRING.H
![Contributors](https://img.shields.io/github/contributors/Autumn64/nsstring.h)
![Stars](https://img.shields.io/github/stars/Autumn64/nsstring.h)
![License](https://img.shields.io/github/license/Autumn64/nsstring.h)
![Issues](https://img.shields.io/github/issues/Autumn64/nsstring.h)
## A free, open-source, simple, memory-safe and lightweight Strings library for C.

## Description
NSSTRING.H is a library that provides an interface to work with text strings as in common high-level programming languages. NSSTRING.H stands for "Non-Standard Strings Header"

## Features
- Fast and efficient.
- Easy to use.
- Works on any C version starting from C99.
- Doesn't require any dependencies besides the standard library.

## Introduction
To create a string, just use the `str_new()` function.
```c
#include <nsstring.h>

int main(void){
    String str = str_new();

    //More code here...
}
```
Strings in NSSTRING.H have only two members: A `value`, and a `length`. This is because a `String` is essentially a `struct`:
```c
typedef struct String{
	char *value;
	size_t length;
} String;
```

Note: The `length` member _always_ includes the null character (`\0`). So, if you do this:
```c
#include <nsstring.h>

int main(void){
    String str1 = str_new();
    str_ccopy(&str1, "Hello World!");

    //More code here...
}
```
The member `str1.length` will have a value of `13` instead of `12`, as `str.value` = `Hello World!\0`.

Whenever you're finished using a String, don't forget to `str_free()` it to prevent memory leaks!
```c
str_free(&str1);
```

## Reference
Please read [NSSTRING.H Reference](REFERENCE.md).

## Extra information
Thanks so much to all of our [contributors](https://github.com/Autumn64/nsstring.h/graphs/contributors).

#### All the code in this repository is licensed under the [MIT License](LICENSE.txt). This library is meant to be distributed for non-commercial purposes, and neither this project's owner nor its contributors are responsible for the use anyone outside of it might give to the software provided and its assets.