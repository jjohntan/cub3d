/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/29 18:42:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void freelist(char **list)
{
    int i;

    i = -1;
    if (!list)
        return ;
    while (list[++i])
        free(list[i]);
    free (list);
    list = NULL;
}
