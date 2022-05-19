#include "shell.h"
/**
 * make_env - Entry
 * @env: environment passed to main
 * Description: make shell environment that returns to currnt environment
 * Return: pointer to new env
 */
char **make_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}
/**
 * free_env - free env
 * @env: environment
 * Description: free shell env
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
