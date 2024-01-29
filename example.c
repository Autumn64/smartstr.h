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
