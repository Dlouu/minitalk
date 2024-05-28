/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:29:56 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 13:54:44 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# ifdef __linux__
#  define NULL_PTR "(nil)"
# else
#  define NULL_PTR "0x0"
# endif

typedef struct s_ret
{
	int			written;
	int			error;
}		t_ret;

// ft_printf
int		ft_printf(const char *format, ...);

// ft_printf arguments
void	pf_arg_char(char c, t_ret *ret);
void	pf_arg_str(char *s, t_ret *ret);
void	pf_arg_int(long long int n, t_ret *ret);
void	pf_arg_uint(unsigned int n, t_ret *ret);
void	pf_arg_hex(unsigned int hex, t_ret *ret);
void	pf_arg_uhex(unsigned int hex, t_ret *ret);
void	pf_arg_ptr(uintptr_t ptr, t_ret *ret);
void	pf_arg_pcent(t_ret *ret);

#endif
