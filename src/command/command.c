/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:44:41 by luebina           #+#    #+#             */
/*   Updated: 2024/10/11 14:43:31 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd(t_token *tokens)
{
	int	ct;

	ct = 0;
	while (tokens && tokens->type != PIPE && tokens->type != REDIR_IN
		&& tokens->type != REDIR_OUT && tokens->type != HEREDOC)
	{
		if (tokens->type == WORD)
			ct++;
		tokens = tokens->next;
	}
	return (ct);
}

char	**parse_command(t_token *tokens)
{
	t_token	*tmp;
	char	**cmd;
	int		i;

	tmp = tokens;
	i = 0;
	cmd = (char **)malloc((count_cmd(tokens) + 1) * sizeof(char *));
	if (!cmd)
	{
		perror("malloc");
		return (NULL);
	}
	tmp = tokens;
	while (tmp && tmp->type != PIPE && tmp->type != REDIR_IN
		&& tmp->type != REDIR_OUT && tmp->type != HEREDOC)
	{
		if (tmp->type == WORD)
		{
			cmd[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	*search_path(const char *filename)
{
	char	*path;
	char	*value;
	char	*end;
	char	*dup;

	value = getenv("PATH");
	while (*value)
	{
		path = (char *)malloc(ft_strlen(value) + ft_strlen(filename) + 2);
		if (!path)
			return (NULL);
		ft_bzero(path, ft_strlen(value));
		end = ft_strchr(value, ':');
		if (end)
			ft_strlcpy(path, value, end - value + 1);
		else
			ft_strlcpy(path, value, ft_strlen(value));
		ft_strlcat(path, "/", ft_strlen(value) + 2);
		ft_strlcat(path, filename, ft_strlen(value) + ft_strlen(filename) + 3);
		if (access(path, X_OK) == 0)
		{
			dup = ft_strdup(path);
			return (dup);
		}
		if (!end)
			return (NULL);
		value = end + 1;
		free(path);
	}
	return (NULL);
}

void	execute_external(char **cmd_lst)
{
	pid_t		pid;
	int			status;
	extern char	**environ;
	char		*cmd;

	/* printf("%s, %s\n", cmd_lst[0], cmd_lst[1]); */
	cmd = search_path(cmd_lst[0]);
	if (!cmd)
		return ;
	pid = fork();
	if (pid == 0)
	{
		execve(cmd, cmd_lst, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");
}

void	command(t_token *tokens)
{
	char	**cmd_lst;

	cmd_lst = parse_command(tokens);
	/* if (is_builtin(cmd[0])) */
	/* 	execute_builtin(cmd); */
	/* else */
	/* 	execute_external(cmd); */
	/* if (!is_builtin(cmd_lst[0])) */
	execute_external(cmd_lst);
}
