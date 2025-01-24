/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:05:58 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 20:35:12 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int nbr)
{
	int		i;
	long	lnbr;

	lnbr = (long)nbr;
	i = 0;
	if (lnbr < 0)
	{
		i += ft_print_char('-');
		lnbr *= -1;
	}
	if (lnbr >= 10)
	{
		i += ft_print_nbr(lnbr / 10);
		i += ft_print_nbr(lnbr % 10);
	}
	if (lnbr >= 0 && lnbr <= 9)
	{
		i += ft_print_char(lnbr + '0');
	}
	return (i);
}
