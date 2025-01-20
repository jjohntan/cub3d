/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/01/20 16:52:18 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

// int	check_char()
// {
// 	int	h;
// 	int	w;
	
// 	while (map[])
// 	{
// 		while (map[][])
// 		{
// 			if ([][] != '0'&& [][] != '1' && [][]!= 'N' && [][]!= 'S' && [][]!='E' && [][]!= 'W')
// 				return (0);
// 		}
// 	}
// 	return (1);
// }
void	check_extension(char *av)
{
	int	len;
	
	len = ft_strlen(av) - 4;
	if (ft_strncmp(&av[len], ".cub", 4) != 0)
		ft_putstr_fd("Error\n invalid extension", 2);
}

int main(int ac, char **av)
{
	// t_data	data;
	(void)ac;
	
	check_extension(av[1]);
}
