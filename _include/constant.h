/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:41:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/29 12:41:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

// Window
# define WIND_W 1200  // Width
# define WIND_H 750   // Height

// Keyboard
# define ESC 65307
# define AW_LEFT 65361   // Arrow left
# define AW_RIGHT 65363  // Arrow right
# define UP 119    // W
# define DOWN 115  // S
# define LEFT 97   // A
# define RIGHT 100 // D
# define SPACEBAR 32

// Mouse
# define LEFT_CLICK 1
# define DIFF 10   // Mouse sensitivify. Increase to make player turn faster

// 2d map
# define TILE 64            // Actual tile size
# define S 4                // Scale down factor  for minimap
# define MINI_T (TILE / S)  // Minimap tile
# define MINI_W 150         // Minimap window 200 x 200

// Angle
# define PI 3.14159265358979323846 
# define DEG_90 (PI / 2)
# define DEG_180 (PI)
# define DEG_270 (3 * PI) / 2
# define DEG_360 (2 * PI)

// Access coordinate
# define X 0
# define Y 1
#define MIN 0
#define MAX 1

// Player
# define MOVE 4.0          // Moving speed
# define ROTATE 0.0523599  // Turning speed
# define BOUND 8   // Player's boundary - for collision detection
# define REACH 25  // Player's reach to unlock door

//----------------------------------------------------------------------------
// COLOR
//----------------------------------------------------------------------------

// 2D map
# define P1_POS   0xFF0000    // RED
# define P1_FOV   0x80FFFF00  // YELLOW with %50 alpha
# define WALL     0xFF        // BLUE
# define SPACE    0xA9A9A9    // GREY
# define DOOR     0x03AC13    // GREEN
// VOID BLACK 

#endif
