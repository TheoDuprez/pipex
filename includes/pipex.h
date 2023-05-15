/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:05:26 by tduprez           #+#    #+#             */
/*   Updated: 2023/05/15 11:59:27 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

# define PIPE_ERR 1
# define FORK_ERR 2
# define OPEN_ERR 3
# define NB_ARG_ERR 4
# define ENV_ERR 5
# define DUP_ERR 6
# define EXECVE_ERR 7
# define SPLIT_ERR 8
# define MALLOC_ERR 9
# define GNL_ERR 10
# define CMD_ERR 11

typedef struct s_pipes
{
	char	*cmd;
	char	**cmd_path;
	char	**cmd_args;
	int		*pid;
	int		input;
	int		nb_cmd;
	int		output;
	int		pfd[2];
	int		status;
	int		exit_status;
	int		here_doc_fd;
	int		here_doc_index;
}	t_pipes;

// process.c //
void	process(t_pipes *pipes, char **argv, char **envp, int i);

// fd_management.c //
int		is_here_doc(char **argv);
void	file_input(t_pipes *pipes, char *file);
void	file_output(t_pipes *pipes, char **argv, int argc);
void	ft_here_doc(t_pipes *pipes, char **argv);

// get_path.c //
char	*get_env_path(char **envp);
char	*get_cmd_path(t_pipes *pipes);

// pipex_utils.c //
void	check_file(int i, char **argv, t_pipes *pipes);

#endif
