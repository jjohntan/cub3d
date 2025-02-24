/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:25:48 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 20:35:37 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(void *ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (!ptr)
	{
		i += write(1, "0", 1);
		return (i);
	}
	i += ft_print_num_base((unsigned long)ptr, "0123456789abcdef");
	return (i);
}
