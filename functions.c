#include “main.h”
#include <stdio.h>
#include <stdarg.h>
/**
* _printf - Custom printf function
* Description: This function emulates the printf function in C.
* providing formatted output to the standard output.
* Parameters:
* format: A format specifying how the arguments are formatted and printed.
* Variable arguments that correspond to placeholders in the format string.
* Returns: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
/*function implementation*/
{

if (format == NULL)
return (-1); /*Return an error code for NULL format string*/

int char_print = 0;

va_list list_of_args;

va_start(list_of_args, format);

while (*format)
{
if (*format != '%')
{
putchar(*format); /*Print non-% characters directly*/
char_print++;
}
else
{
format++;
if (*format == 'c')
{
/*Handle character argument*/
char c = va_arg(list_of_args, int);
putchar(c);
char_print++;
}
else if (*format == 's')
{
/*Handle string argument*/
char *str = va_arg(list_of_args, char *);
if (str == NULL)
{
fputs("(null)", stdout); /*Print (null) for NULL strings*/
char_print += 6; /*Length of "(null)"*/
}
else
{
fputs(str, stdout);
char_print += strlen(str);
}
}
else if (*format == 'd')
{
/*Handle integer argument*/
int num = va_arg(list_of_args, int);
char buffer[50]; /*Assuming a maximum of 49 digits for an integer*/
int len = snprintf(buffer, sizeof(buffer), "%d", num);
fputs(buffer, stdout);
char_print += len;
}
else
{
putchar('%'); /*Print '%' for unsupported format specifiers*/
char_print++;
if (*format != '\0')
{
putchar(*format);
char_print++;
}
}
}
format++;
}
va_end(list_of_args);
return (char_print);
}

int main(void)
{
int result = _printf("Hello, %s! The answer is %d. Character: %c\n", "world", 42, 'A');

printf("\nTotal characters printed: %d\n", result);
return (0);
}
