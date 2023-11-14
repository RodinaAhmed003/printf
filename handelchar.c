#include "main.h"

/**
 * handle_unsigned - Handles the %u specifier
 * Converts an unsigned int argument to decimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_unsigned(va_list args, char **buffer, int *count);

/**
 * handle_octal - Handles the %o specifier
 * Converts an unsigned int argument to octal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_octal(va_list args, char **buffer, int *count);

/**
 * handle_hex - Handles the %x and %X specifiers
 * Converts an unsigned int argument to hexadecimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 * @uppercase: Flag indicating whether to use uppercase letters for %X
 */
void handle_hex(va_list args, char **buffer, int *count, int uppercase);

/**
 * create_handlers - Creates the array of handlers
 *
 * Return: Pointer to the array of handlers
 */
handler_t *create_handlers(void)
{
    static handler_t handlers[] = {
        {'c', handle_char},
        {'s', handle_string},
        {'%', handle_percent},
        {'d', handle_int},
        {'i', handle_int},
        {'u', handle_unsigned}, /* Added handler for %u specifier */
        {'o', handle_octal},    /* Added handler for %o specifier */
        {'x', handle_hex},      /* Added handler for %x specifier */
        {'X', handle_hex},      /* Added handler for %X specifier */
        {'\0', NULL}
    };
    return handlers;
}

/**
 * handle_unsigned - Handles the %u specifier
 * Converts an unsigned int argument to decimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_unsigned(va_list args, char **buffer, int *count)
{
    unsigned int value = va_arg(args, unsigned int);
    char decimal[20]; /* Buffer to hold the decimal representation */
    itoa(value, decimal, 10); /* Convert the value to decimal representation */
    int length = strlen(decimal);

    for (int i = 0; i < length; i++) {
        (*buffer)[(*count)++] = decimal[i];
    }
}

/**
 * handle_octal - Handles the %o specifier
 * Converts an unsigned int argument to octal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_octal(va_list args, char **buffer, int *count)
{
    unsigned int value = va_arg(args, unsigned int);
    char octal[23]; /* Buffer to hold the octal representation */
    itoa(value, octal, 8); /* Convert the value to octal representation */
    int length = strlen(octal);

    for (int i = 0; i < length; i++) {
        (*buffer)[(*count)++] = octal[i];
    }
}

/**
 * handle_hex - Handles the %x and %X specifiers
 * Converts an unsigned int argument to hexadecimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 * @uppercase: Flag indicating whether to use uppercase letters for %X
 */
void handle_hex(va_list args, char **buffer, int *count, int uppercase)
{
    unsigned int value = va_arg(args, unsigned int);
    char hex[17]; /* Buffer to hold the hexadecimal representation */
    itoa(value, hex, 16); /* Convert the value to hexadecimal representation */
    int length = strlen(hex);

    for (int i = 0; i < length; i++) {
        if (uppercase) {
            (*buffer)[(*count)++] = toupper(hex[i]);
        } else {
            (*buffer)[(*count)++] = hex[i];
        }
    }
}

/**
 * _printf - Prints formatted output
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count, i;
    char *buffer;
    const char *p = format;
    handler_t *h;
    handler_t *handlers;

    if (formatI apologize. It seems that the code got cut off in the previous response. Here's the complete modified code, following the Betty style guidelines:

```c
#include "main.h"

/**
 * handle_unsigned - Handles the %u specifier
 * Converts an unsigned int argument to decimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_unsigned(va_list args, char **buffer, int *count);

/**
 * handle_octal - Handles the %o specifier
 * Converts an unsigned int argument to octal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_octal(va_list args, char **buffer, int *count);

/**
 * handle_hex - Handles the %x and %X specifiers
 * Converts an unsigned int argument to hexadecimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 * @uppercase: Flag indicating whether to use uppercase letters for %X
 */
void handle_hex(va_list args, char **buffer, int *count, int uppercase);

/**
 * create_handlers - Creates the array of handlers
 *
 * Return: Pointer to the array of handlers
 */
handler_t *create_handlers(void)
{
    static handler_t handlers[] = {
        {'c', handle_char},
        {'s', handle_string},
        {'%', handle_percent},
        {'d', handle_int},
        {'i', handle_int},
        {'u', handle_unsigned}, /* Added handler for %u specifier */
        {'o', handle_octal},    /* Added handler for %o specifier */
        {'x', handle_hex},      /* Added handler for %x specifier */
        {'X', handle_hex},      /* Added handler for %X specifier */
        {'\0', NULL}
    };
    return handlers;
}

/**
 * handle_unsigned - Handles the %u specifier
 * Converts an unsigned int argument to decimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_unsigned(va_list args, char **buffer, int *count)
{
    unsigned int value = va_arg(args, unsigned int);
    char decimal[20]; /* Buffer to hold the decimal representation */
    itoa(value, decimal, 10); /* Convert the value to decimal representation */
    int length = strlen(decimal);

    for (int i = 0; i < length; i++) {
        (*buffer)[(*count)++] = decimal[i];
    }
}

/**
 * handle_octal - Handles the %o specifier
 * Converts an unsigned int argument to octal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_octal(va_list args, char **buffer, int *count)
{
    unsigned int value = va_arg(args, unsigned int);
    char octal[23]; /* Buffer to hold the octal representation */
    itoa(value, octal, 8); /* Convert the value to octal representation */
    int length = strlen(octal);

    for (int i = 0; i < length; i++) {
        (*buffer)[(*count)++] = octal[i];
    }
}

/**
 * handle_hex - Handles the %x and %X specifiers
 * Converts an unsigned int argument to hexadecimal representation
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 * @uppercase: Flag indicating whether to use uppercase letters for %X
 */
void handle_hex(va_list args, char **buffer, int *count, int uppercase)
{
    unsigned int value = va_arg(args, unsigned int);
    char hex[17]; /* Buffer to hold the hexadecimal representation */
    itoa(value, hex, 16); /* Convert the value to hexadecimal representation */
    int length = strlen(hex);

    for (int i = 0; i < length; i++) {
        if (uppercase) {
            (*buffer)[(*count)++] = toupper(hex[i]);
        } else {
            (*buffer)[(*count)++] = hex[i];
        }
    }
}

/**
 * _printf - Prints formatted output
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count, i;
    char *buffer;
    const char *p = format;
    handler_t *h;
    handler_t *handlers;

    if (format == NULL) {
        return (-1);
    }

    va_start(args, format);
    handlers
