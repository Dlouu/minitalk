/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:30:45 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:51:53 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_arg_hex(unsigned int hex, t_ret *ret)
{
	int	temp;

	temp = ft_nlen_ubase(hex, 16);
	if (temp != ft_putnbr_base(hex, "0123456789abcdef"))
		ret->error = 1;
	ret->written += temp;
}

void	pf_arg_uhex(unsigned int hex, t_ret *ret)
{
	int	temp;

	temp = ft_nlen_ubase(hex, 16);
	if (temp != ft_putnbr_base(hex, "0123456789ABCDEF"))
		ret->error = 1;
	ret->written += temp;
}
