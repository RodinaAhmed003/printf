This  Repository is totally created by Rodina and Manar
Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);

Returns: the number of characters printed (excluding the null byte used to end output to strings)

write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
Handle the following conversion specifiers:
d
i
Handle the following custom conversion specifiers:
b: the unsigned int argument is converted to binary
Handle the following conversion specifiers:
u
o
x
X
