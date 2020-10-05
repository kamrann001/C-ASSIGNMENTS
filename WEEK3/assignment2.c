#include <stdio.h>
/*because of the limitations of built-in functions
 I used character pointers for strings not character arrays and in order to change character pointers
 i passed a pointer to the pointer. It also makes it possible to use different sized strings*/

void swapStrings(char **destination, char **source);

int main()
{
    char *str1 = "Hello";
    char *str2 = "World";
    
    printf("str1: %s, str2 : %s\n", str1,str2);
    swapStrings(&str1,&str2);
    printf("str1: %s, str2 : %s\n", str1,str2);


    return 0;
}

void swapStrings(char **destination, char **source)
{
    char *temp = *destination;
    *destination = * source;
    *source = temp;
    
}

