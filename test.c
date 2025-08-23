#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);

int	main(int ac, char *av[])
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

char	*ft_strdup(char *s)
{
	int		i;
	char	*string;

	i = 0;
	while (s[i])
		i++;
	string = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	line[70000];
	static int	buffer_pos = 0;
	static int	pos = 0;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos <= pos)
		{
			buffer_pos = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (buffer_pos <= 0)
				break ;
		}
		line[i] = buffer[pos];
		i++;
		pos++;
		if (line[pos - 1] == '\n' || (size_t)i >= sizeof(line))
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
