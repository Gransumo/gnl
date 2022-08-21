
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char	*new;
	char	*aux;
	if(fd < 0)
		return (NULL);
	if(save != NULL && ft_strchr(save, '\n') != NULL)
	{
		new = ft_set_new(save);
		save = ft_set_saved(save);
		return (new);
	}
	aux = get_line(save, fd);
	printf(".|%s|.", save);
	new = ft_strjoin(save, aux);
	if(new == NULL)
		return (NULL);
	return (new);
}

char	*get_line(char	*save, int fd)
{
	char	*buff;
	ssize_t	n_bytes;

	n_bytes = 1;
	while(ft_strchr(save, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if(buff == NULL)
			return (NULL);
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if(n_bytes < 0)
			return(NULL);
		save = ft_strjoin(save, buff);
		if(n_bytes == 0)
			break ;
	}
	if(n_bytes == 0 && ft_strlen(save) == 0 && ft_strlen(buff) == 0)
		return (NULL);
	buff = ft_set_new(save);
	save = ft_set_saved(save);
	return(save);
}

char	*ft_set_new(char *save)
{
	char	*new;
	size_t	i;
	size_t	len;

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

	i = 0;
	len = len_new(save);
	n_save = malloc(ft_strlen(&save[len]) + 1);
	if(n_save == NULL)
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

	fd = open("text", O_RDONLY);
	printf("primera: %sfin", get_next_line(fd));
	printf("segunda:\n%s", get_next_line(fd));
	return (0);
}
