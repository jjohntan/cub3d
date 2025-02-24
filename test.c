/*
#include <stdio.h>

int blankstr(char *str)
{
	while(*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

int main()
{
		printf("%d\n",blankstr("            "));
		printf("%d\n",blankstr("       N     "));
}
*/

// #include "libft/libft.h"
// #include <stdio.h>

// void	check_color_format(char *str)
// {
// 	int	i;
// 	int	comma;

// 	i = 0;
// 	comma = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ',')
// 		{
// 			comma++;
// 			i++;
// 		}
// 		else if (ft_isdigit(str[i]) != 0)
// 			i++;
// 		else
// 		{
// 			printf("hi\n");
// 			exit(1);
// 		}
// 	}
// 	if (comma != 2)
// 	{
// 		printf("hello\n");
// 		exit(1);
// 	}
// }

// int main()
// {
// 	check_color_format("0,255,0");
// }
// #include "libft/libft.h"
// #include <stdlib.h>
// void	error_exit(char *str)
// {
// 	ft_putstr_fd(str, 2);
// 	exit(1);
// }

// int main ()
// {
// 	error_exit("Error\nhello");
// }

#include <stdio.h>
#include <stdlib.h>

void	flood_fill(char **map, int x, int y)
{
	int height = 5;
	int width = 6;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	printf("Visiting (%d, %d): %c\n", x, y, map[y][x]);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (x == 0 || x == width - 1 || y == 0
		|| y == height - 1)
	{
		if (map[y][x] != '1')
		{
			printf("hello\n");
			exit(1);
		}
	}
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int main()
{
	char row0[] = "   111";
	char row1[] = "   101";
	char row2[] = "111101";
	char row3[] = "1100N1";
	char row4[] = "111111";
	char *map[] = { row0, row1, row2, row3, row4, NULL };
	
	flood_fill(map, 4, 3);
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}