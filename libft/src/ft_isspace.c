/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:05:50 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/04/19 15:53:03 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
isspace()
checks for white-space characters.  In the "C" and "POSIX" locales, 
these are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'), 
horizontal tab ('\t'), and vertical tab ('\v').
*/

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
