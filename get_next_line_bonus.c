/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:42:39 by ehossain          #+#    #+#             */
/*   Updated: 2025/01/02 20:07:53 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int		fd[5];
// 	char	*get_line;
// 	int		i;
//
// 	i = 0;
// 	get_line = ft_calloc(1, sizeof(char));
// 	fd[0] = open("test1.txt", O_RDONLY);
// 	printf("fd = [%d]\n", fd[0]);
// 	fd[1] = open("test2.txt", O_RDONLY);
// 	printf("fd = [%d]\n", fd[1]);
// 	fd[2] = open("test3.txt", O_RDONLY);
// 	printf("fd = [%d]\n", fd[2]);
// 	fd[3] = open("test4.txt", O_RDONLY);
// 	printf("fd = [%d]\n", fd[3]);
// 	fd[4] = open("test5.txt", O_RDONLY);
// 	printf("fd = [%d]\n", fd[4]);
// 	while (i != 5)
// 	{
// 		if (get_line != NULL)
// 		{
// 			get_line = get_next_line(fd[0]);
// 			printf("get_line = %s", get_line);
// 			get_line = get_next_line(fd[1]);
// 			printf("get_line = %s", get_line);
// 			get_line = get_next_line(fd[2]);
// 			printf("get_line = %s", get_line);
// 			get_line = get_next_line(fd[3]);
// 			printf("get_line = %s", get_line);
// 			get_line = get_next_line(fd[4]);
// 			printf("get_line = %s", get_line);
// 		}
// 		i++;
// 	}
// 	for (int i = 0; i < 5; i++)
// 	{
// 		close(fd[i]);
// 	}
// 	return (0);
// }

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= -1 || fd > 1024)
	{
		free(buffer[fd]);
		free(line);
		return (NULL);
	}
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		free(line);
		return (NULL);
	}
	free(line);
	line = ft_set_next_line(buffer[fd]);
	buffer[fd] = ft_set_remaining(buffer[fd]);
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	ssize_t	read_bytes;
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
	return (tmp_buffer = NULL, buffer);
}

char	*ft_set_next_line(char *buffer)
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
		tmp_buffer[i] = buffer[i];
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
	if (!buffer)
		return (NULL);
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
		tmp_buffer[j++] = buffer[i++];
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
