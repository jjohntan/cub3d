/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:38:40 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/12 18:51:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>     // open, close
# include <unistd.h>    // read, write
# include <stdio.h>     // printf, perror
# include <string.h>    // strerror (Also need errno)
# include <error.h>
# include <errno.h>
# include <stdlib.h>     // exit, malloc, free 
# include <math.h>       // All math function
# include <stdbool.h>    // true ,false
# include <X11/keysym.h> // Linux key macros
# include <X11/X.h>

# include "mlx/mlx.h"    // All Minilibx functions
# include "lib/libft.h"  // libft authorize

# include "constant.h"
# include "struct.h" 
# include "prototype.h"

#endif