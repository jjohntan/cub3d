/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:03:33 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 20:35:22 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_num_base(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= ft_strlen(base))
	{
		i += ft_print_num_base(nbr / ft_strlen(base), base);
		i += ft_print_num_base(nbr % ft_strlen(base), base);
	}
	else
		i += ft_print_char(base[nbr]);
	return (i);
}
