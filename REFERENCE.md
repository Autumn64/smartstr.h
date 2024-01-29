# SMARTSTR.H Reference
## Compatibility
SMARTSTR.H has only been tested with GCC/MinGW. It only uses the standard C library ([libc](https://en.wikipedia.org/wiki/C_standard_library)), and it should work on any C versions after C99. If you find compatibility issues with a specific C version or compiler, please open an [issue](https://codeberg.org/Autumn64/smartstr.h/issues) or, if you prefer, contribute to the project creating a [pull request](https://codeberg.org/Autumn64/smartstr.h/pulls).
## Macros
```c
#define STR_SUCCESS 0
#define STR_FAILURE -1
#define STR_TRUE 1
#define STR_FALSE 0
```
## String
```c
typedef struct String{
	char *value;
	size_t length;
} String;
```
`typedef struct` with two members:
- `char *value`
- `size_t length`

## str_new
```c
String str_new();
```
Creates a `String` object and initializes its members to `str.value = NULL` and `str.length = 0`, then returns the generated object.

## str_free
```c
void str_free(String *str);
```
Frees the memory assigned to `str->value` and sets the value of `str->length` to `0`.

## str_print, str_println, str_fprint, str_fprintln
```c
void str_print(String str);
void str_println(String str);
void str_fprint(String str, FILE *stream);
void str_fprintln(String str, FILE *stream);
```
Prints the specified String to `stdout` (`str_print`, `str_println`) or to the specified `FILE` (`str_fprint`, `str_fprintln`). The `ln` functions add a new-line character (`\n`) at the end.

## str_readln
```c
int str_readln(String *str, FILE *stream);
```
Reads characters from the specified `FILE` until it finds a new-line character (`\n`), a null character (`\0`) or an `EOF`, and stores them in the specified String. 

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

## str_scopy, str_ccopy
```c
int str_scopy(String *dest, String src);
int str_ccopy(String *dest, char *src);
```
Copies the contents of `src` to `dest` String, overwriting any previous contents of `dest`. 

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

## str_sappend, str_cappend
```c
int str_sappend(String *dest, String src);
int str_cappend(String *dest, char *src);
```
Appends the contents of `src` at the end of `dest` String.

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

## str_scomp, str_ccomp
```c
int str_scomp(String str1, String str2);
int str_ccomp(String str1, char *str2);
```
Compares the information of `str1` and `str2`. Returns `STR_TRUE` if they are equal, or `STR_FALSE` if they're not.

## str_scount, str_ccount
```c
size_t str_scount(String str, String pattern);
size_t str_ccount(String str, char *pattern);
```
Returns the number of occurrences of a pattern in the specified String.

## str_sreplace, str_creplace
```c
long int str_sreplace(String *str, char *pattern, String replacement);
long int str_creplace(String *str, char *pattern, char *replacement);
```
Replaces all ocurrences of `pattern` with `replacement` in the specified String. 

Returns the number of elements replaced if no errors occurred, otherwise returns `STR_FAILURE`.

## str_remove
```c
long int str_remove(String *str, char *pattern);
```
Removes all occurrences of `pattern` from the specified String.

Returns the number of elements removed if no errors occured, otherwise returns `STR_FAILURE`.

## str_lower
```c
int str_lower(String *str);
```
Converts all alphabetic characters of the specified String to lowercase.

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

NOTE: UTF-8 characters outside of standard ASCII might not be converted properly.

## str_upper
```c
int str_upper(String *str);
```
Converts all alphabetic characters of the specified String to uppercase.

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

NOTE: UTF-8 characters outside of standard ASCII might not be converted properly.

## str_reverse
```c
int str_reverse(String *str);
```
Reverses the specified String.

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

NOTE: UTF-8 characters outside of standard ASCII might not be reversed properly.

## str_setvf
```c
int str_setvf(String *dest, const char *format, ...);
```
Writes the contents of `format` to the specified String. If `format` includes [format specifiers](https://en.cppreference.com/w/c/io/fprintf) the additional arguments are formatted and inserted in the resulting String replacing their respective specifiers.

Returns `STR_SUCCESS` if no errors occurred, otherwise returns `STR_FAILURE`.

## str_charat
```c
int str_charat(String str, size_t index);
```
Returns the character at the specified position from the specified String as a `int`, or `EOF` if `index` is equal or greater than `str.length`.

## Example code
```c
#include <stdio.h>
#include "smartstr.h"

int main(void){
    String name, city, whatever, everything, stats;
    printf("Enter your name: ");
    name = str_new(); str_readln(&name, stdin);
    printf("Enter your city: ");
    city = str_new(); str_readln(&city, stdin);
    printf("Now enter whatever you want!: ");
    whatever = str_new(); str_readln(&whatever, stdin);
    everything = str_new();
    str_scopy(&everything, name);
    str_cappend(&everything, ", "); str_sappend(&everything, city);
    str_cappend(&everything, ", "); str_sappend(&everything, whatever);

    stats = str_new();
    str_setvf(&stats, "Name has %zu characters, City has %zu characters, Phrase has %zu characters.\n", name.length, city.length, whatever.length);
    
    printf("Hello, %s! This is the information you entered:\n", name.value);
    printf("Name: "); str_println(name);
    printf("City: "); str_println(city);
    printf("Phrase: "); str_println(whatever);
    printf("Now everything separated by commas: "); str_println(everything);
    printf("Stats:\n");
    str_fprintln(stats, stdout); //Basically the same as str_println()

    str_free(&name); str_free(&city); str_free(&whatever); 
    str_free(&everything); str_free(&stats);

    return 0;
}
```

Try this example code [here](example.c).