/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:02 by jetan             #+#    #+#             */
/*   Updated: 2024/06/25 15:25:05 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t elementCount, size_t elementSize);
void	gnl_bzero(void *s, size_t n);

#endif