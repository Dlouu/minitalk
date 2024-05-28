/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:51:04 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:50:41 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
}
