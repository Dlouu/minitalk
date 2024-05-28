/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:30:45 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:52:05 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_arg_ptr(uintptr_t ptr, t_ret *ret)
{
	int	temp;

	if (ptr == 0)
	{
		temp = ft_strlen(NULL_PTR);
		if (temp != ft_putstr(NULL_PTR))
			ret->error = 1;
		ret->written += temp;
	}
	else
	{
		temp = ft_putstr("0x");
		if (temp == -1)
			ret->error = 1;
		ret->written += temp;
		temp = ft_nlen_ubase(ptr, 16);
		if (temp != ft_putnbr_base(ptr, "0123456789abcdef"))
			ret->error = 1;
		ret->written += temp;
	}
}
