/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:56:19 by tduprez           #+#    #+#             */
/*   Updated: 2023/05/15 12:01:33 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	all_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (i == count)
		return (1);
	return (0);
}

void	check_file(int i, char **argv, t_pipes *pipes)
{
	if (argv[i + 2 + pipes->here_doc_index][0] == 0)
	{
		write(1, "permission denied:\n", ft_strlen("permission denied:\n"));
		ft_close(4, pipes->pfd[0], pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_path);
		exit(CMD_ERR);
	}
	else if (all_spaces(argv[i + 2 + pipes->here_doc_index]) == 1)
	{
		write(1, "command not found:\n", ft_strlen("command not found:\n"));
		ft_close(4, pipes->pfd[0], pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_path);
		exit(CMD_ERR);
	}
}
