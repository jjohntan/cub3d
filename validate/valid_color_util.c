/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:40:16 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/20 16:40:16 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

bool check_comma(char *s)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while (s[++i])
    {
        if (s[i] == ',')
        {
            if (i == 0 || s[i + 1] == ',' || !s[i + 1])
                return (false);
            count++;
        }
    }
    return (count == 2);
}

void split_rgb(char *s, char **split)
{
    int i;

    i = 0;
    split[i++] = s;
    while (*s)
    {
        if (*s == ',')
        {
            *s = '\0';
            split[i++] = s + 1;
        }
        s++;
    }
}

bool valid_num(char **color)
{
    int i;
    int j;
    int len;

    i = -1;
    while (++i < 3)
    {
        j = -1;
        len = 0;
        color[i] = trim_space(color[i], BOTH);
        while (color[i][++j])
        {
            if (!ft_isdigit(color[i][j]))
                return (false);
            len++;
        }
        if (!len || len > 3)
            return (false);
    }
    return (true);
}

bool in_range(char **color, int *num)
{
    int i;
    int result;

    i = -1;
    while (++i < 3)
    {
        result = ft_atoi(color[i]);
        if (result < 0 || result > 255)
            return (false);
        num[i] = result;
    }
    return (true);
}

int rgb_2_color(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}