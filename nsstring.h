#ifndef NSSTRING_H_
#define NSSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define STR_SUCCESS 0
#define STR_FAILURE -1
#define STR_TRUE 1
#define STR_FALSE 0

typedef struct String{
	char *value;
	size_t length;
} String;

String str_new();
void str_free(String *str);
void str_print(String str);
void str_println(String str);
void str_fprint(String str, FILE *stream);
void str_fprintln(String str, FILE *stream);
int str_readln(String *str, FILE *stream);
int str_scopy(String *dest, String src);
int str_ccopy(String *dest, char *src);
int str_sappend(String *dest, String src);
int str_cappend(String *dest, char *src);
int str_scomp(String str1, String str2);
int str_ccomp(String str1, char *str2);
size_t str_scount(String str, String pattern);
size_t str_ccount(String str, char *pattern);
long int str_sreplace(String *str, char *pattern, String replacement);
long int str_creplace(String *str, char *pattern, char *replacement);
long int str_remove(String *str, char *pattern);
int str_lower(String *str);
int str_upper(String *str);
int str_reverse(String *str);
int str_setvf(String *dest, const char *format, ...);
int str_charat(String str, size_t index);

#endif //NSSTRING_H_
