/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:52:07 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:43 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pipe	create_pipe(void)
{
	t_pipe	pipe_struct;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Error creating a pipe");
		exit(EXIT_FAILURE);
	}
	pipe_struct.read_pipe = pipe_fd[0];
	pipe_struct.write_pipe = pipe_fd[1];
	return (pipe_struct);
}
