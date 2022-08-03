/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:56:43 by abackman          #+#    #+#             */
/*   Updated: 2022/08/03 13:56:49 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(char **str, size_t size)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		if (str[size] == NULL)
			break ;
		else
		{
			ft_bzero(str[size], ft_strlen((const char *)str[size]));
			free(str[size]);
			//str[size] = NULL;
		}
		i++;
	}
	free(str);
	return (NULL);
}
