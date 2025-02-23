/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blankstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:54:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 13:54:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

// Check if string is filled with isspace characters
bool	blankstr(char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (!ft_isspace(s[i]))
			return (false);
	}
	return (true);
}

/*
int main()
{
	printf("Blank str\n");
	printf("%d\n", blankstr(""));
	printf("%d\n", blankstr("       "));
	printf("%d\n", blankstr("     \n  "));

	printf("\n\nNone-blank str\n");
	printf("%d\n", blankstr("    5  "));
	printf("%d\n", blankstr("   -2134"));
}
*/