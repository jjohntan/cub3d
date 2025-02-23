/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:08:09 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 14:08:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/*
trim_space
==============================================================================
- remove white_space in string 
- see "ft_isspace" for which char considered white_space

----------------------------------------------------------------------------
Options available
- L_TRIM:  "_____hello____" -->  "hello____"
- R_TRIM:  "_____hello____" -->  "_____hello"
- BOTH  :  "_____hello____" -->  "hello"

*/
char	*trim_space(char *s, int option)
{
	int	i;

	if (option == L_TRIM || option == BOTH)
	{
		while (ft_isspace(*s))
			s++;
	}
	if (option == R_TRIM || option == BOTH)
	{
		i = ft_strlen(s);
		while (i > 0 && ft_isspace(s[i - 1]))
			s[--i] = '\0';
	}
	return (s);
}

/*
int main()
{
	char s1[] = "     hello    ";
	printf("[%s]\n", trim_space(s1, L_TRIM));

	char s2[] = "     hello    ";
	printf("[%s]\n", trim_space(s2, R_TRIM));

	char s3[] = "     hello    ";
	printf("[%s]\n", trim_space(s3, BOTH));

	char s4[] = "     \n    ";
	printf("[%s]\n", trim_space(s4, BOTH));

	char s5[] = "";
	printf("[%s]\n", trim_space(s5, BOTH));
}
*/