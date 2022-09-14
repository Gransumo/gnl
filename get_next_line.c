
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd)
{
	static char	*save;
	char	*new;
	char	*line;

	if(fd < 0)
		return (NULL);
	if(save != NULL && (ft_strchr(save, '\n') != NULL || ft_strchr(save, '\0') != NULL))
	{
		new = ft_set_new(save);
		save = ft_set_saved(save);
		return (new);
	}
	save = get_line(save, fd);
	new = ft_set_new(save);
	save = ft_set_saved(save);
	if(new == NULL)
		return (NULL);
	line = new;
	free(new);
	return (line);
}

char	*get_line(char	*save, int fd)
{
	char	*buff;
	size_t	n_bytes;


	n_bytes = 1;
	while(!ft_strchr(save, '\n'))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if(buff == NULL)
			return (NULL);
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if(n_bytes < 0)
		{
			free(buff);
			return(NULL);
		}
		buff[n_bytes] = 0;
		save = ft_strjoin(save, buff);
		if(n_bytes == 0)
			break ;
	}
	if(n_bytes == 0 && !ft_strlen(save) && !ft_strlen(buff))
		return (NULL);
	return(save);
}

void leaks()
{
	system("leaks a.out");
}
char	*ft_set_new(char *save)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = len_new(save);
	if(save == NULL)
		return (NULL);
	new = malloc (len + 1);
	if(new == NULL)
		return(NULL);
	while(i < len)
	{
		new[i] = save[i];
		i++;
	}
	new[i] = '\0';
	return(new);
}

char	*ft_set_saved(char *save)
{
	char	*n_save;
	size_t	i;
	size_t	len;

	i = 0;
	len = len_new(save);
	if(!save)
		return (NULL);
	n_save = malloc(ft_strlen(&save[len]) + 1);
	if(!n_save)
		return (NULL);
	while(save[len + i] != '\0')
	{
		n_save[i] = save[len + i];
		i++;
	}
	n_save[i] = '\0';
	free(save);
	return(n_save);
}

int main()
{
	int fd;

	atexit(leaks);
	fd = open("text", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
