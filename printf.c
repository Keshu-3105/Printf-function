#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

int printf(const char *input, ...);

#endif

int printf(const char *print, ...) {

    int char_printing = 0;
    va_list lists_of_args;

    if (print == NULL){
        return -1;
    }

    va_start(lists_of_args, print);

    while (*print){
        if (*print != '%') {
            write(1, print, 1);
            char_printing++;
        } else {
            print++;
            if (*print == '\0') {
                break;
            }

            if (*print == '%') {
                write(1, print, 1);
                char_printing++;
            }
            else if (*print == 'c') {
                char c = va_arg(lists_of_args, int);
                write(1, &c, 1);
                char_printing++;
            }
            else if (*print == 's') {
                char *string = va_arg(lists_of_args, char *);
                int string_length = strlen(string);

                write(1, string, string_length);
                char_printing += string_length;
            }
            else if (*print == 'd') {
                int integer = va_arg(lists_of_args, int);
                int temp = integer;

                if (integer == 0) {
                    write(1, "0", 1);
                    char_printing++;
                } else {
                    char number[15];
                    int i = 15 - 1;

                    while (integer != 0) {
                        number[i--] = integer % 10 + '0';
                        integer = integer / 10;
                    }

                    int character_count = 15 - i - 1;

                    write(1, &number[i + 1], character_count);
                    char_printing += character_count;
                }
            }
        }

        print++;
    }

    va_end(lists_of_args);

    return char_printing;
}

int main()
{
    printf("Printf function is runnning\n");
    printf("This is to show you that integer is also run and it will print nineteen in numbers %d\n", 19);
    printf("Next line will be blank to show that blank function is also working\n");
    printf("\n");
    printf("this is for showing characher printing %c\n", 'y');
    printf("this is for showing characher printing %s \n", "working");
    printf("this is for showing misslenious printing %%\n");
    printf("This if for showing multiple printing: %c is the first character of %s\n", 'k', "Keshav");

    return 0;
    
}