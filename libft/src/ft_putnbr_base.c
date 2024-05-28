/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:39 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:50:11 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_base_check(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count >= 2)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_recursive(unsigned long int nb, char *base, int *check, \
			unsigned int size_base)
{
	if (nb > size_base - 1)
	{
		ft_recursive(nb / size_base, base, check, size_base);
		ft_recursive(nb % size_base, base, check, size_base);
	}
	else
		*check += ft_putchar(nb[base]);
}

int	ft_putnbr_base(long long int n, char *base)
{
	int				check;
	long long int	nb;
	unsigned int	size_base;

	check = 0;
	nb = n;
	if (!base)
		return (0);
	size_base = ft_strlen(base);
	if (size_base <= 1 || ft_base_check(base) == 0)
		return (0);
	if (n < 0 && size_base != 16)
	{
		check += ft_putchar('-');
		nb = -nb;
	}
	ft_recursive(nb, base, &check, size_base);
	return (check);
}
