/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_management.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:16:14 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/07 13:38:28 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	file_input(t_pipes *pipes, char *file)
{
	pipes->input = open(file, O_RDONLY);
	if (pipes->input == -1)
		perror("Open");
}

void	file_output(t_pipes *pipes, char **argv, int argc)
{
	pipes->output = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipes->output == -1)
		perror("Open");
}

int	is_here_doc(char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
		return (true);
	return (false);
}

static void	protect_here_doc(int fd)
{
	if (fd == -1)
		perror("Open");
}

void	ft_here_doc(t_pipes *pipes, char **argv)
{
	char	*line;

	pipes->here_doc_fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	protect_here_doc(pipes->here_doc_fd);
	while (true)
	{
		write(1, "pipe heredoc>", 13);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_close(1, pipes->output, pipes->here_doc_fd);
			ft_perror("Error with gnl\n", GNL_ERR);
		}
		if (!ft_strncmp(argv[2], line, ft_strlen(argv[2])))
		{
			ft_close(1, pipes->here_doc_fd);
			free(line);
			break ;
		}
		write(pipes->here_doc_fd, line, ft_strlen(line));
		free(line);
	}
}
