# NSSTRING.H
[![Pull requests](https://img.shields.io/badge/dynamic/json.svg?label=pull%20requests&style=for-the-badge&color=limegreen&url=https://codeberg.org/api/v1/repos/Autumn64/nsstring.h&query=open_pr_counter)](https://codeberg.org/Autumn64/nsstring.h/pulls)
[![Issues](https://img.shields.io/badge/dynamic/json.svg?label=issues&style=for-the-badge&color=red&url=https://codeberg.org/api/v1/repos/Autumn64/nsstring.h&query=open_issues_count)](https://codeberg.org/Autumn64/nsstring.h/issues)
[![Stars](https://img.shields.io/badge/dynamic/json.svg?label=stars&style=for-the-badge&color=yellow&url=https://codeberg.org/api/v1/repos/Autumn64/nsstring.h&query=stars_count)](https://codeberg.org/Autumn64/nsstring.h)
[![License](https://img.shields.io/badge/license-LGPL_v3-blue?label=license&style=for-the-badge&url=)](https://codeberg.org/Autumn64/nsstring.h/src/branch/main/LICENSE.txt)
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
Thanks so much to all of our [contributors](https://codeberg.org/Autumn64/nsstring.h/activity/yearly).

#### All the code in this repository is licensed under the [GNU Lesser General Public License version 3 or later](LICENSE). This library is meant to be distributed for non-commercial purposes, and neither this project's owner nor its contributors are responsible for the use anyone outside of it might give to the software provided and its assets.
