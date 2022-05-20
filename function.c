#include "shell.h"
/**
 * print_error - ..
 * @var: ..
 * @msg: ...
 * Description: .....
 * Return: ...
 */
void print_error(t_var *var, char *msg)
{
	char *count;

	_puts2(var->argv[0]);
	_puts2(": ");
	count = _uitoa(var->com_count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(var->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}
/**
 * _puts2 - ....
 * @str: ....
 * Description: ...
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}
}
/**
 * _uitoa - ...
 * @count: .....
 * Description: .....
 * Return: .....
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
