/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:03:19 by tduprez           #+#    #+#             */
/*   Updated: 2023/05/15 12:00:03 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_process(t_pipes *pipes, char **argv, int i);
static void	first_child(t_pipes *pipes);
static void	between_child(t_pipes *pipes);
static void	last_child(t_pipes *pipes);

void	process(t_pipes *pipes, char **argv, char **envp, int i)
{
	free_pointer(1, pipes->pid);
	init_process(pipes, argv, i);
	ft_close(1, pipes->pfd[0]);
	if (i == 0)
		first_child(pipes);
	else if (i == pipes->nb_cmd - 1)
		last_child(pipes);
	else
		between_child(pipes);
	ft_close(3, pipes->pfd[1], pipes->input, pipes->output);
	execve(pipes->cmd, pipes->cmd_args, envp);
	free_str_arr(1, pipes->cmd_args);
	free_pointer(1, pipes->cmd);
	ft_perror("execve", EXECVE_ERR);
}

static void	init_process(t_pipes *pipes, char **argv, int i)
{
	check_file(i, argv, pipes);
	pipes->cmd_args = ft_split(argv[i + 2 + pipes->here_doc_index], ' ');
	if (!pipes->cmd_args || !pipes->cmd_args[0])
	{
		ft_close(4, pipes->pfd[0], pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_path);
		exit(SPLIT_ERR);
	}
	pipes->cmd = get_cmd_path(pipes);
	if (!pipes->cmd)
	{
		ft_close(4, pipes->pfd[0], pipes->pfd[1], pipes->input, pipes->output);
		write(2, pipes->cmd_args[0], ft_strlen(pipes->cmd_args[0]));
		write(2, "\n", 1);
		free_str_arr(2, pipes->cmd_args, pipes->cmd_path);
		exit(127);
	}
}

static void	first_child(t_pipes *pipes)
{
	if (dup2(pipes->input, STDIN_FILENO) == -1)
	{
		ft_close(3, pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_args);
		free_pointer(1, pipes->cmd);
		exit(DUP_ERR);
	}
	if (dup2(pipes->pfd[1], STDOUT_FILENO) == -1)
	{
		ft_close(3, pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_args);
		free_pointer(1, pipes->cmd);
		exit(DUP_ERR);
	}
}

static void	between_child(t_pipes *pipes)
{
	if (dup2(pipes->pfd[1], STDOUT_FILENO) == -1)
	{
		ft_close(3, pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_args);
		free_pointer(1, pipes->cmd);
		exit(DUP_ERR);
	}
}

static void	last_child(t_pipes *pipes)
{
	if (dup2(pipes->output, STDOUT_FILENO) == -1)
	{
		ft_close(3, pipes->pfd[1], pipes->input, pipes->output);
		free_str_arr(1, pipes->cmd_args);
		free_pointer(1, pipes->cmd);
		exit(DUP_ERR);
	}
}
