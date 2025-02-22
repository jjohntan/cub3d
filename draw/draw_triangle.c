/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:31:05 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/31 22:31:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void min_max(int *i, int *bound)
{
    bound[MIN] = fmin(fmin(i[0], i[1]), i[2]);
    bound[MAX] = fmax(fmax(i[0], i[1]), i[2]);
}

void draw_triangle(int x[3], int y[3], int color, t_game *g)
{
    int i[2];
    int k[2];
    int y_bound[2];
    int x_bound[2];
    float matrix[3];
    float area;

    min_max(x, x_bound);
    min_max(y, y_bound);
    i[Y] = y_bound[MIN] - 1;
    area = (y[1] - y[2]) * (x[0] - x[2]) + (x[2] - x[1]) * (y[0] - y[2]);
    while (++i[Y] <= y_bound[MAX])
    {
        i[X] = x_bound[MIN] - 1;
        while (++i[X] <= x_bound[MAX])
        {
            k[X] = i[X] - x[2];
            k[Y] = i[Y] - y[2];
            matrix[0] = ((y[1] - y[2]) * k[X] + (x[2] - x[1]) * k[Y]) / area;
            matrix[1] = ((y[2] - y[0]) * k[X] + (x[0] - x[2]) * k[Y]) / area;
            matrix[2] = 1 - matrix[0] - matrix[1];
            if (matrix[0] > 0 && matrix[1] > 0 && matrix[2] > 0)
                putpx_disp(i[X], i[Y], color, g);
        }
    }
}
