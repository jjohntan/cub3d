/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:57 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:07:57 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchr(int c)
{
	char	chr;

	chr = c;
	write(1, &chr, 1);
	return (1);
}
