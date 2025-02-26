/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:14:18 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/26 14:14:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

bool	read_line(char fd, char **s)
{
	int	i;

	*s = get_next_line(fd);
	if (*s)
	{
		i = ft_strlen(*s);
		while (i > 0 && ((*s)[i - 1] == '\n' || (*s)[i - 1] == '\r'))
			(*s)[--i] = '\0';
		return (true);
	}
	return (false);
}
