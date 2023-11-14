#include "main.h"

/**
 * handle_binary - Handles the %b specifier
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_binary(va_list args, char **buffer, int *count);

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
		{'b', handle_binary}, /* Added handler for %b specifier */
		{'\0', NULL}
	};
	return handlers;
}

/**
 * handle_binary - Handles the %b specifier
 * Converts an unsigned int argument to binary
 * @args: The va_list containing the argument
 * @buffer: Pointer to the output buffer
 * @count: Pointer to the character count
 */
void handle_binary(va_list args, char **buffer, int *count)
{
	unsigned int value = va_arg(args, unsigned int);
	char binary[33]; /* Buffer to hold the binary representation (32 bits + 1 null terminator) */
	itoa(value, binary, 2); /* Convert the value to binary representation */
	int length = strlen(binary);

	for (int i = 0; i < length; i++)
	{
		(*buffer)[(*count)++] = binary[i];
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

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	handlers = create_handlers();
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
	{
		return (-1);
	}
	count = 0;
	for (; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			buffer[count++] = *p;
			continue;
		}
		p++;

		if (*p == '\0')
		{
			count--;
			break;
		}
		for (h = handlers; h->specifier != '\0'; h++)
		{
			if (h->specifier == *p)
			{
				h->handler(args, &buffer, &count);
				break;
			}
		}
		if (h->specifier == '\0')
		{
			buffer[count++] = '%';
			buffer[count++] = *p;
		}
	}
	for (i = 0; i < count; i++)
	{
		_putchar(buffer[i]);
	}
	free(buffer);
	va_end(args);
	return (count);
}
