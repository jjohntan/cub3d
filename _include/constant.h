/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:41:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/10 22:49:51 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

// Window
//----------------------------------------------------------------------------
# define WIND_W 1200  // Width
# define WIND_H 750   // Height

// Keyboard
//----------------------------------------------------------------------------
# define ESC 65307
# define AW_LEFT 65361   // Arrow left
# define AW_RIGHT 65363  // Arrow right
# define UP 119    // W
# define DOWN 115  // S
# define LEFT 97   // A
# define RIGHT 100 // D
# define VIEW 118  // V
# define SPACEBAR 32
# define NUM_1 49
# define NUM_2 50

// Mouse
//----------------------------------------------------------------------------
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define DIFF 10   // Mouse sensitivity. Increase to make player turn faster

// 2D Map Info
//----------------------------------------------------------------------------
# define TILE 64            // Actual tile size
# define S 4                // Scale down factor  for minimap
# define MINI_T (TILE / S)  // Minimap tile
# define MINI_W 150         // Minimap window 200 x 200

// 2D Map Color
//----------------------------------------------------------------------------

// 2D map
# define P1_POS   0xFF0000    // RED
# define P1_FOV   0x80FFFF00  // YELLOW with %50 alpha
# define WALL     0xFF        // BLUE
# define SPACE    0xA9A9A9    // LIGHT GREY
# define UNLOCK   0xBACDBE    // LIGHT GREEN
# define LOCK     0x364b3a    // DARK GREEN
# define VOID     0xFF000000  // BLACK / NOTHING 

// Angle calculation
//----------------------------------------------------------------------------
# define PI 3.14159265358979323846 
# define DEG_90 (PI / 2)
# define DEG_180 (PI)
# define DEG_270 (3 * PI) / 2
# define DEG_360 (2 * PI)

// Access coordinate index
//----------------------------------------------------------------------------
# define X 0
# define Y 1
#define MIN 0
#define MAX 1

// Player Param
//----------------------------------------------------------------------------
# define MOVE 4.0          // Moving speed
# define ROTATE 0.0523599  // Turning speed
# define BOUND 10    // Player's boundary - for collision detection
# define REACH 60   // Player's reach to unlock door
# define ANIMATE 10 // Delay time to switch images, 
//-                    bigger value means slower animation

//----------------------------------------------------------------------------
// Asset

// Sprite
#define KNIFE_0 "./asset/sprite/knife0.xpm"
#define KNIFE_1 "./asset/sprite/knife1.xpm"
#define KNIFE_2 "./asset/sprite/knife2.xpm"
#define KNIFE_3 "./asset/sprite/knife3.xpm"

#define PISTOL_0 "./asset/sprite/pistol0.xpm"
#define PISTOL_1 "./asset/sprite/pistol1.xpm"
#define PISTOL_2 "./asset/sprite/pistol2.xpm"
#define PISTOL_3 "./asset/sprite/pistol3.xpm"
#define PISTOL_4 "./asset/sprite/pistol4.xpm"

# define SPRITE_W 300
# define SPRITE_H 200

// Door (Bonus)
#define IMG_DOOR "./asset/door.xpm"

// Index to access texture array
#define NORTH 0
#define SOUTH 1
#define EAST  2
#define WEST  3
#define DOOR  4

//----------------------------------------------------------------------------
// Output message color

# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define RESET "\033[0m"

//----------------------------------------------------------------------------
// Raycasting & wall slice parameter

# define FOV  (PI / 3)       // Field of view - 60degree
# define STEP (FOV / WIND_W) // Ray increment step

# define PROJECTED_D ((WIND_W / 2) / tan(FOV / 2))

//----------------------------------------------------------------------------
// Parsing

#define NO 0
#define SO 1
#define EA 2
#define WE 3
#define F  4
#define C  5

//----------------------------------------------------------------------------
// Trimming white_space

#define L_TRIM 1
#define R_TRIM 2
#define BOTH 3

#endif