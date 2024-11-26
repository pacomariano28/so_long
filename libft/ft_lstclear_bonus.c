/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:01:47 by frmarian          #+#    #+#             */
/*   Updated: 2024/04/29 13:21:00 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	while (*lst != NULL)
	{
		lst_temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_temp;
	}
	*lst = NULL;
}
