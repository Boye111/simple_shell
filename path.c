#include "shell.h"
/**
 * path_execute - path to be executed
 * @command: full path to a command
 * @var: pointer
 * Description: Executes a command in the path
 * Return: 0 or 1
 */
int path_execute(char *command, t_var *var)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_error(var, NULL);
		if (child_pid == 0)
		{
			if (execve(command, var->av, var->env) == -1)
				print_error(var, NULL);
		}
		else
		{
			wait(&var->ext_status);
			if (WIFEXITED(var->ext_status))
				var->ext_status = WEXITSTATUS(var->ext_status);
			else if (WIFSIGNALED(var->ext_status)
					&& WTERMSIG(var->ext_status) == SIGINT)
				var->ext_status = 130;
			return (0);
		}
		var->ext_status = 127;
		return (1);
	}
	else
	{
		print_error(var, ": Permission denied\n");
		var->ext_status = 126;
	}
	return (0);
}
/**
 * find_path - find path of a variable
 * @env: array of environmental variables
 * Description: finds PATH
 * Return: node that contains path or failure
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}
/**
 * check_for_path - function
 * @var: var
 * Description: chcks for command in path
 * Return: ....
 */
void check_for_path(t_var *var)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int i = 0, r = 0;
	char **path_tokens;
	struct stat buf;

	if (check_for_dir(var->av[0]))
		r = execute_cwd(var);
	else
	{
		path = find_path(var->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = tokenize(path_dup, ":");
			for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
			{
				check = _strcat(path_tokens[i], var->av[0]);
				if (stat(check, &buf) == 0)
				{
					r = path_execute(check, var);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
				var->ext_status = 127;
				new_exit(var);
			}
		}
		if (path == NULL || path_tokens[i] == NULL)
		{
			print_error(var, ": not found\n");
			var->ext_status = 127;
		}
		free(path_tokens);
	}
	if (r == 1)
		new_exit(var);
}
/**
 * execute_cwd - ....
 * @var: pointer to struc of variables
 * Description: Executes command in the cwd
 * Return: 0 or 1
 */
int execute_cwd(t_var *var)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(var->av[0], &buf) == 0)
	{
		if (access(var->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				print_error(var, NULL);
			if (child_pid == 0)
			{
				if (execve(var->av[0], var->av, var->env) == -1)
					print_error(var, NULL);
			}
			else
			{
				wait(&var->ext_status);
				if (WIFEXITED(var->ext_status))
					var->ext_status = WEXITSTATUS(var->ext_status);
				else if (WIFSIGNALED(var->ext_status)
						&& WTERMSIG(var->ext_status) == SIGINT)
					var->ext_status = 130;
				return (0);
			}
			var->ext_status = 127;
			return (1);
		}
		else
		{
			print_error(var, ": Permission denied\n");
			var->ext_status = 126;
		}
		return (0);
	}
	print_error(var, ": not found\n");
	var->ext_status = 127;
	return (0);
}
/**
 * check_for_dir - .......
 * @str: string
 * Description: .....
 * Return: 1 or 0
 */
int check_for_dir(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}

