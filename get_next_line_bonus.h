/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:53:24 by serhouni          #+#    #+#             */
/*   Updated: 2022/11/01 04:55:19 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *result);
char	*opti_strjoin(char *s1, char *s2);
char	*get_line(char *buffer);
char	*next_line(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);

#endif