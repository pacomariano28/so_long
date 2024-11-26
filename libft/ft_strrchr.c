/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:38:18 by frmarian          #+#    #+#             */
/*   Updated: 2024/04/22 12:41:21 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	strlenght;

	strlenght = ft_strlen(str);
	if ((char)chr == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (strlenght >= 0)
	{
		if (str[strlenght] == (char)chr)
			return ((char *)(str + strlenght));
		strlenght --;
	}
	return (NULL);
}

/* 
- We've casted the returned pointer because function
request a pointer with char type.
*/