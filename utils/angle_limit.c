/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:01:04 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/31 10:01:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

float angle_limit(float i)
{
    if (i >= DEG_360)
        i -= DEG_360;
    else if (i < 0)
        i += DEG_360;
    return (i);
}
