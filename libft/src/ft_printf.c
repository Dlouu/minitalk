/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:26:23 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/03/06 12:49:53 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	valid_fmt(const char *format)
{
	if (ft_strchr("cspdiuxX%", *format) != NULL)
		return (1);
	return (0);
}

static void	check_format(va_list *args, const char **format, t_ret *ret)
{
	if (**format == 'c')
		pf_arg_char(va_arg(*args, int), ret);
	if (**format == 's')
		pf_arg_str(va_arg(*args, char *), ret);
	if (**format == 'p')
		pf_arg_ptr(va_arg(*args, uintptr_t), ret);
	if (**format == 'd' || **format == 'i')
		pf_arg_int(va_arg(*args, int), ret);
	if (**format == 'u')
		pf_arg_uint(va_arg(*args, unsigned int), ret);
	if (**format == 'x')
		pf_arg_hex(va_arg(*args, unsigned int), ret);
	if (**format == 'X')
		pf_arg_uhex(va_arg(*args, unsigned int), ret);
	if (**format == '%')
		pf_arg_pcent(ret);
	(*format)++;
}

static void	percent_error(const char **format, t_ret *ret)
{
	ret->error = 1;
	format++;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_ret	ret;

	va_start(args, format);
	ret.error = 0;
	ret.written = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0' && valid_fmt(format + 1))
		{
			format++;
			check_format(&args, &format, &ret);
		}
		else if (*format == '%' && *(format + 1) == '\0')
			percent_error(&format, &ret);
		else
		{
			ret.written += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	if (ret.error == 1)
		return (-1);
	return (ret.written);
}
