/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:28:57 by tduprez           #+#    #+#             */
/*   Updated: 2023/05/15 11:31:06 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_env_path(char **envp)
{
	if (!*envp)
		return (NULL);
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp && !ft_strncmp("PATH", *envp, 4))
		return (*envp + 5);
	return (NULL);
}

char	*get_cmd_path(t_pipes *pipes)
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	if (access(pipes->cmd_args[0], F_OK | X_OK) == 0)
		return (free_str_arr(1, pipes->cmd_path), \
			ft_strdup(pipes->cmd_args[0]));
	if (pipes->cmd_args[0][0] == '/')
		return (write(2, "no such file or directory: ", 27), NULL);
	while (pipes->cmd_path[i])
	{
		temp = ft_strjoin(pipes->cmd_path[i], "/");
		if (pipes->cmd_args[0][0] != '/')
			path = ft_strjoin(temp, pipes->cmd_args[0]);
		if (access(path, F_OK | X_OK) == 0)
			return (free_pointer(1, temp), \
				free_str_arr(1, pipes->cmd_path), path);
		free_pointer(2, temp, path);
		i++;
	}
	return (write(2, "command not found: ", 19), NULL);
}
