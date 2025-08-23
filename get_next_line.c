/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/14 12:32:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*next_line;

	(void)ac;
	fd = 0;
	fd = open(av[1], O_RDONLY);
	next_line = ft_calloc(1, sizeof(char));
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
	static char	*read_file;
	char		*new_line;

	new_line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file = ft_read_file(fd, read_file);
	if (!read_file)
		return (NULL);
	new_line = ft_set_line(read_file);
	read_file = ft_set_remaining(read_file);
	return (new_line);
}

char	*ft_read_file(int fd, char *buffer)
{
	int		read_bytes;
	char	*tmp_buffer;

	read_bytes = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (free(buffer), free(tmp_buffer), NULL);
		}
		tmp_buffer[read_bytes] = '\0';
		buffer = ft_str_free_join(buffer, tmp_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp_buffer);
	return (buffer);
}

char	*ft_set_line(char *buffer)
{
	int		i;
	char	*tmp_buffer;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp_buffer = ft_calloc(i + 2, sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp_buffer[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		tmp_buffer[i] = '\n';
		i++;
	}
	tmp_buffer[i] = '\0';
	return (tmp_buffer);
}

char	*ft_set_remaining(char *buffer)
{
	int		i;
	int		j;
	char	*tmp_buffer;

	ft_inisialize(&i, &j);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	i++;
	while (buffer[i])
	{
		tmp_buffer[j] = buffer[i];
		i++;
		j++;
	}
	tmp_buffer[j] = '\0';
	free(buffer);
	return (tmp_buffer);
}

void	ft_inisialize(int *i, int *j)
{
	*i = 0;
	*j = 0;
	return ;
}
