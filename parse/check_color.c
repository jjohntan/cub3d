
#include "../_include/cub3d.h"

/**
 * @brief This function check the colors range in [0,255]
 */
void	color_range(int *color)
{
	int	i;

	if (!color)
		return ;
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			error_exit("Error\nInvalid color range");
		i++;
	}
}

/**
 * @brief This function check the color format
 */
void	check_color_format(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma++;
			i++;
		}
		else if (ft_isdigit(str[i]) != 0)
			i++;
		else
			error_exit("Error\nInvalid character\n");
	}
	if (comma != 2)
		error_exit("Error\ntwo comma needed\n");
}

void valid_color(t_game *data)
{
	if (!data->c || !data->f)
		error_exit("Error\nMissing color info\n");
	parse_rgb(data->c, &data->ceiling);
	parse_rgb(data->f, &data->floor);
}