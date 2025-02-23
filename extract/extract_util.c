/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:33:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/21 22:33:28 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/*
flush_gnl
==============================================================================
- gnl will leak if we didn't read file until EOF 
- because static char inside gnl still holding the balance string (malloc)
- do while loop until EOF so gnl not holding anything
*/

void	flush_gnl(int fd)
{
	char	*s;

	while (true)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free(s);
	}
}

/*
read_line
==============================================================================
- Wrapper for get_next_line
- Remove ending \n and \r character from string
- Return boolean value: 

Note: If get_next_line() returns a string, it will be assigned to **s 
	 (which is a pointer reference)
	 
------------------------------------------------------------------------------
Return 
	true  = gnl return string ptr 
	false = gnl return NULL ptr
*/

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

/*
int main()
{
	char *s;
	int fd = open("hello.txt", O_RDONLY);
	while (read_line(fd, &s))
	{
		printf("[%s] | ", s);
		free(s);
	}
	close(fd);
}
*/