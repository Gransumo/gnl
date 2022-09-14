
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char	*new;

	// printf("save: %s\n", save);
	if (fd < 0)
		return (NULL);
	if (save != NULL && (ft_strchr(save, '\n')))
	{
		new = ft_set_new(save);
		save = ft_set_saved(save);
		return (new);
	}
//	save = ft_strjoin(save, get_line(save, fd));
	save = get_line(save, fd);
	new = ft_set_new(save);
	save = ft_set_saved(save);
	return (new);
}



char	*get_line(char	*save, int fd)
{
	char	*buff;
	int		n_bytes;
	size_t	count;

	count = 0;
	n_bytes = 0;
	while(!ft_strchr(save, '\n'))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if(buff == NULL)
			return (NULL);
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		count += n_bytes;
		if(count <= 0)
		{
			free(buff);
			return(save);
		}
		buff[n_bytes] = 0;
		save = ft_strjoin(save, buff);
		if(n_bytes == 0)
			break ;
	}
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

	if (save == NULL)
		return (NULL);
	i = 0;
	len = len_new(save);
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

	if (!save)
		return (NULL);
	i = 0;
	len = len_new(save);
	n_save = malloc(ft_strlen(&save[len]) + 1);
	if(!n_save)
		return (NULL);
	while(save[len + i] != '\0')
	{
		n_save[i] = save[len + i];
		i++;
	}
	n_save[i] = 0;
	if(ft_strlen(&save[len]) == 0)
	{
		free(n_save);
		n_save = NULL;
	}
	free(save);
	return(n_save);
}

/* int main()
{
	int fd;

	//atexit(leaks);
	fd = open("text", O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	printf("\n\n\n\n1: %s\n", line);
	free(line);

	return (0);
}  */
