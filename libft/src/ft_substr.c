/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:32 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:51:20 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if ((len == 1 && s[0] == '\0') || start >= s_len)
		len = 0;
	else
		s += start;
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
