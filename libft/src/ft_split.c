/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:26 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:50:30 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_count_str(char const *s, char c)
{
	int	str;
	int	i;

	str = 0;
	i = 0;
	while (s && s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			str++;
		i++;
	}
	return (str);
}

static int	ft_len_str(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count_str;
	char	**result;

	i = 0;
	if (!s)
		return (NULL);
	count_str = ft_count_str(s, c);
	result = (char **)malloc(sizeof(char *) * (count_str + 1));
	if (!result)
		return (NULL);
	while (count_str > i)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_substr(s, 0, ft_len_str(s, c));
		if (!(result[i]))
			return (ft_free(result));
		s += ft_len_str(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
