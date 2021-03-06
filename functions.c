#include "shell.h"
/**
 * _puts - ...
 * @str: string
 * Description: ..
 * Return: chars printed or -1
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
/**
 * _strdup - ...
 * @strdp: ....
 * Description: ....
 * Return: ....
 */
char *_strdup(char *strdp)
{
	char *copy;

	int len, i;

	if (strdp == 0)
		return (NULL);
	for (len = 0; strdp[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));
	for (i = 0; i <= len; i++)
		copy[i] = strdp[i];
	return (copy);
}
/**
 * _strcmpr- ....
 * @str1: ....
 * @str2: ...
 * Description: ...
 * Return: ...
 */
int _strcmpr(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}
/**
 * _strcat - ...
 * @str1: ....
 * @str2: ...
 * Description: ...
 * Return: ...
 */
char *_strcat(char *str1, char *str2)
{
	char *new;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (str1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; str1[len1]; len1++)
			;
	}
	if (str2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; str2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	new = malloc(newlen * sizeof(char));
	if (new == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new[i] = str1[i];
	new[i] = '/';
	for (j = 0; j < len2; j++)
		new[i + 1 + j] = str2[j];
	new[len1 + len2 + 1] = '\0';
	return (new);
}
/**
 * _strlen - ....
 * @str: ..
 * Description: ...
 * Return: ...
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;
	for (len = 0; str[len]; len++)
		;
	return (len);
}
