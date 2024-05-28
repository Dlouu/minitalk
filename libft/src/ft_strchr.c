/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:46:26 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:50:33 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == '\0' && *s == '\0')
		return ((char *)s);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		if (*(s + 1) == (unsigned char)c)
			return ((char *)s + 1);
		s++;
	}
	return (NULL);
}
