/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:04:26 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:43 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}