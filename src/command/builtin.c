/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:41:49 by luebina           #+#    #+#             */
/*   Updated: 2024/10/11 14:39:30 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0
		|| ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "pwd", 3) == 0
		|| ft_strncmp(cmd, "export", 6) == 0
		|| ft_strncmp(cmd, "unset", 5) == 0
		|| ft_strncmp(cmd, "env", 3) == 0
		|| ft_strncmp(cmd, "exit", 4) == 0)
		return (1);
	return (0);
}

/* int	execute_builtin(char **cmd) */
/* { */
/* 	if (ft_strncmp(cmd[0], "echo", 4) == 0) */
/* 		return (builtin_echo(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "cd", 2) == 0) */
/* 		return (builtin_cd(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "pwd", 3) == 0) */
/* 		return (builtin_pwd(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "export", 6) == 0) */
/* 		return (builtin_export(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "unset", 5) == 0) */
/* 		return (builtin_unset(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "env", 3) == 0) */
/* 		return (builtin_env(cmd)); */
/* 	else if (ft_strncmp(cmd[0], "exit", 4) == 0) */
/* 		return (builtin_exit(cmd)); */
/* 	return (-1); */
/* } */
