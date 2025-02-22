/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:25:43 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/20 12:25:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static bool check_color(char *input, int *color);
static void error_1(char *info);
static void error_2(char *info);

/*
valid_color
==============================================================================
- Check if there are exactly 2 commas ([,]).
- A comma cannot be at the start, end, or followed by another comma (,,).
- Split the string by replacing commas ([,]) with \0.
- For each split part:
    * Trim spaces and ensure it contains at most 3 digits (0-9).
    * Convert to an integer using atoi (must be 0–255).
- Finally, combine RGB into a single value.

--------------------------------------------------------------------------
Param
- char *s → Extracted color string.
- int *color → Pointer to store the final result

--------------------------------------------------------------------------
Return 
- true : OK
- false: wrong rgb format | not_digit | number out of range

*/
bool valid_color(t_game *g)
{
    if(check_color(g->info[C], &g->ceiling) 
        && check_color(g->info[F] , &g->floor))
        return (true);
    return (false);
}

static bool check_color(char *input, int *color)
{
    char *s;
    char *split[3];
    int num[3];

    if (check_comma(input))
    {   
        s = ft_strdup(input);
        split_rgb(s, split);
        if (valid_num(split) && in_range(split, num))
        {
            *color = rgb_2_color(num[0], num[1], num[2]);
            return (free(s), true);
        }
        return (free(s), error_1(input), false);
    }
    return (error_2(input), false);
}

static void error_1(char *info)
{
    err_msg("Incorrct RGB value range", "0 - 255 only", info);
}

static void error_2(char *info)
{
    err_msg("Incorrct RGB color format", "\"Red , Blue, Green\"", info);
}

/*
void answer(char *s)
{
    int color;
    printf("color : \"%s\"\n", s);
    
    if (valid_color(s, &color))
        printf("%d\n", color);
    printf("--------------\n");
}

int main()
{
    printf("\nError\n=================\n");
    char s0[] = "255  ,, 80 40";
    char s1[] = "255  ,, 80 , 40";
    char s2[] = "255 , 80, 17,  18";
    char s3[] = "255 , 80,";
    char s4[] = "255 80 80";
    char s5[] = "255 , 80, ";
    char s6[] = ",84 90, 12 2";
    char s7[] = "-12 ,32 ,32";
    char s8[] = "5,0,-1";
    char s9[] = "a,b,c";
    char s10[] = "255,,";
    char s11[] = " , , ";
    char s12[] = "0, 5, 991";
    char s13[] = "0, 5002, 200";

    answer(s0);
    answer(s1);
    answer(s2);
    answer(s3);
    answer(s4);
    answer(s5);
    answer(s6);
    answer(s7);
    answer(s8);
    answer(s9);
    answer(s10);
    answer(s11);
    answer(s12);
    answer(s13);

    printf("\n\nOK\n=================\n");
    char s21[] = "255, 255, 255";
    char s22[] = "255,100,155";
    char s23[] = "0   ,    0  ,   0";
    char s24[] = "0,111,25";

   
    answer(s21);
    answer(s22);
    answer(s23);
    answer(s24);
}
*/