#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
/**
* main - Entry point of the program
* Description: This function serves as the entry point of the program.
* It is called when the program is executed, and it typically contains the
* main logic of the program.
* Return: Always 0 (indicating successful execution)
*/
int main(void)
{
/* Custom printf function */
int _printf(const char *format, ...);

/* Custom conversion specifier functions */
int print_char(char c, int *char_print);
int print_string(char *str, int *char_print);
int print_integer(int num, int *char_print);
int print_binary(unsigned int num, int *char_print);
int print_unsigned(unsigned int num, int *char_print);
int print_octal(unsigned int num, int *char_print);
int print_hexadecimal(unsigned int num, int uppercase, int *char_print);
int print_reversed(char *str, int *char_print);
int print_rot13(char *str, int *char_print);
return (0);
}
#endif /*MAIN_H*/
