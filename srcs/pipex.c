/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:55:28 by tduprez           #+#    #+#             */
/*   Updated: 2023/05/15 11:26:09 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_pipex(t_pipes *pipes, int argc, char **argv, char **envp);
static void	pipex(t_pipes *pipes, char **argv, char **envp, int i);
static void	pipex_redirect(int what_function, t_pipes *pipes);

int	main(int argc, char **argv, char **envp)
{
	t_pipes	pipes;
	int		i;

	i = 0;
	pipes.exit_status = 0;
	init_pipex(&pipes, argc, argv, envp);
	pipes.pid = malloc(sizeof(int) * pipes.nb_cmd);
	if (!pipes.pid)
	{
		ft_close(2, pipes.input, pipes.output);
		free_str_arr(1, pipes.cmd_path);
		exit(MALLOC_ERR);
	}
	pipex(&pipes, argv, envp, i);
	ft_close(1, pipes.output);
	free_str_arr(1, pipes.cmd_path);
	while (i < pipes.nb_cmd)
		waitpid(pipes.pid[i++], &pipes.status, 0);
	pipes.exit_status = (((pipes.status) & 0xff00) >> 8);
	if (pipes.here_doc_index == 1)
		unlink(".heredoc");
	free_pointer(1, pipes.pid);
	return (pipes.exit_status);
}

static void	init_pipex(t_pipes *pipes, int argc, char **argv, char **envp)
{
	char	*env_path;

	if (argc < 5)
		ft_error("Too few arguments\n", NB_ARG_ERR);
	pipes->here_doc_index = 0;
	env_path = get_env_path(envp);
	if (!env_path)
		ft_error("The environment variable 'PATH' does not exist\n", ENV_ERR);
	file_output(pipes, argv, argc);
	if (is_here_doc(argv))
	{
		pipes->here_doc_index = 1;
		ft_here_doc(pipes, argv);
		file_input(pipes, ".heredoc");
	}
	else
		file_input(pipes, argv[1]);
	pipes->cmd_path = ft_split(env_path, ':');
	if (!pipes->cmd_path)
	{
		ft_close(2, pipes->output, pipes->input);
		ft_error("Error with dynamic allocation in 'ft_split'\n", SPLIT_ERR);
	}
	pipes->nb_cmd = argc - 3 - pipes->here_doc_index;
}

static void	pipex(t_pipes *pipes, char **argv, char **envp, int i)
{
	while (i < pipes->nb_cmd)
	{
		pipex_redirect(0, pipes);
		pipes->pid[i] = fork();
		if (pipes->pid[i] == -1)
		{
			ft_close(4, pipes->input, pipes->output, \
				pipes->pfd[0], pipes->pfd[1]);
			free_str_arr(1, pipes->cmd_path);
			free_pointer(1, pipes->pid);
			ft_perror("Fork", FORK_ERR);
		}
		if (pipes->pid[i] == 0)
			process(pipes, argv, envp, i);
		pipex_redirect(1, pipes);
		ft_close(3, pipes->pfd[0], pipes->pfd[1], pipes->input);
		i++;
	}
}

static void	pipex_redirect(int what_function, t_pipes *pipes)
{
	if (what_function == 0)
	{
		if (pipe(pipes->pfd) == -1)
		{
			ft_close(2, pipes->input, pipes->output);
			free_str_arr(1, pipes->cmd_path);
			free_pointer(1, pipes->pid);
			ft_perror("Pipe", PIPE_ERR);
		}
	}
	else if (what_function == 1)
	{
		if (dup2(pipes->pfd[0], STDIN_FILENO) == -1)
		{
			ft_close(4, pipes->input, pipes->output, \
				pipes->pfd[0], pipes->pfd[1]);
			free_str_arr(1, pipes->cmd_path);
			free_pointer(1, pipes->pid);
			ft_perror("Dup", DUP_ERR);
		}
	}
}
