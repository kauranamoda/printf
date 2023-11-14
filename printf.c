#include "main.h"
int _printf(const char *format, ...)
{
int char_print = 0;
va_list list_of_args;
if (format == NULL)
return (-1); /* Change 'error' to a valid error code*/
va_start(list_of_args, format);
while (*format)
{
if (*format != '%')
{
char temp[2];
temp[0] = *format;
temp[1] = '\0';
fputs(temp, stdout);
char_print++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == 'c')
{
char c = va_arg(list_of_args, int);
char temp[2];
temp[0] = c;
temp[1] = '\0';
fputs(temp, stdout);
char_print++;
}
else if (*format == 's')
{
char *str = va_arg(list_of_args, char *);
if (str != NULL)
{
fputs(str, stdout);
char_print += strlen(str);
}
else
{
fputs("(null)", stdout);
char_print += 6; /*length of "(null)"*/
if (*format == 'd')
{
int num = va_arg(list_of_args, int);
char temp[12]; /* Assuming a reasonable maximum length for an integer*/
int len = snprintf(temp, sizeof(temp), "%d", num);
fputs(temp, stdout);
char_print += len;
}
}
format++;
}
va_end(list_of_args);
}
}
return (char_print);
}
