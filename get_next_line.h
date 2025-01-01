/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/01/01 16:27:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_set_line(char *buffer);
char	*ft_set_remaining(char *buffer);

/* Function below belong to the get_next_line_utils.c file */

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int i);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str_free_join(char *str1, char *str2);
void	ft_inisialize(int *i, int *j);

#endif
