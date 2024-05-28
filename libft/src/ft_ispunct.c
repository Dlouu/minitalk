/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:17:03 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/04/15 19:47:00 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
ispunct()
checks for any printable character which is not a space
or an alphanumeric character.

33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
 !  "  #  $  %  &  '  (  )  *  +  ,  -  .  /
58 59 60 61 62 63 64
 :  ;  <  =  >  ?  @
91 92 93 94 95 96
 [  \  ]  ^  _  `
123 124 125 126
 {   |   }   ~
*/

int	ft_ispunct(int c)
{
	if (c >= 33 && c <= 47)
		return (1);
	else if (c >= 58 && c <= 64)
		return (1);
	else if (c >= 91 && c <= 96)
		return (1);
	else if (c >= 123 && c <= 126)
		return (1);
	return (0);
}
