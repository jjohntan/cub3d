/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:21 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/17 15:30:21 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void	error_1(char *filename, char *extension);
static void	error_2(int code, char *filename);

/*
valid_file
==============================================================================
- check filename str is valid by checking
- correct file extension
- file exist - open()

-----------------------------------------------------------------------------
open() 
- success = fd > 0
- fail = -1 and errno

close()
- success = 0
- fail = -1

-----------------------------------------------------------------------------
Return
- true : valid filename
- false: invalid filename
*/

bool	valid_file(char *filename, char *ext)
{
	int		fd;
	char	*s;

	s = ft_strrchr(filename, '.');
	if (!s || ft_strcmp(s, ext))
	{
		error_1(filename, ext);
		return (false);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_2(errno, filename);
		return (false);
	}
	return (close(fd), true);
}

static void	error_1(char *filename, char *extension)
{
	err_msg("Invalid file extension", extension, filename);
}

static void	error_2(int code, char *filename)
{
	err_msg(strerror(code), NULL, filename);
}

/*
int main()
{
printf("Extension: Error\n");
printf("%d\n", valid_file("", ".txt"));
printf("%d\n", valid_file("Hello", ".txt"));
printf("%d\n", valid_file("Hello.", ".txt"));
printf("%d\n", valid_file("Hello.tx", ".txt"));
printf("%d\n", valid_file("Hello.txt  ", ".txt"));
printf("%d\n", valid_file("./map/bad/color_invalid_rgb.bur", ".cub"));
printf("%d\n", valid_file("./map/bad/color_invalid_rgb", ".cub"));

printf("Can't open or read: Error\n");
printf("%d\n", valid_file("invalid_file.cub", ".cub"));
printf("%d\n", valid_file("./map/bad/color_invalid_rgb.cub", ".cub"));

printf("OK\n");
printf("%d\n", valid_file("Hello.txt", ".txt"));
printf("%d\n", valid_file("map.cub", ".cub"));
printf("%d\n", valid_file("42KL_Norminette.pdf", ".pdf"));
}
*/