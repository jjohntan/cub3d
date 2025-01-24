/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:54:09 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 20:35:57 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_type(const char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (format == 's')
		i += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		i += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_print_num_base(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		i += ft_print_num_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		i += ft_print_num_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		i += ft_print_percent();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_type(format[i + 1], args);
			i++;
		}
		else
		{
			len += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
