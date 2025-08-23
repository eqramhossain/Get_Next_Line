/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 08:58:10 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/26 09:39:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strdup(char *str);

int	main(int ac, char **av)
{
	int		fd;
	char	*next_line;

	(void)ac;
	fd = 0;
	fd = open(av[1], O_RDONLY);
	next_line = calloc(1, sizeof(char));
	while (next_line != NULL)
	{
		free(next_line);
		next_line = get_next_line(fd);
		printf("%s", next_line);
	}
	free(next_line);
	fd = close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	line[70000];
	static int	totol_byte_read = 0;
	static int	buffer_pos = 0;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (totol_byte_read <= buffer_pos)
		{
			totol_byte_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (totol_byte_read <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos];
		i++;
		buffer_pos++;
		if (line[i - 1] == '\n' || (size_t)i >= sizeof(line))
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
