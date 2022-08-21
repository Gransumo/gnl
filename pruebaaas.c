
# include <stdio.h>
# include <stdlib.h>

size_t	len_new(char *save)
{
	size_t	len;

	len = 0;
	while(save[len] != '\0')
	{
		if(save[len] == '\n')
		{
			len ++;
			break ;
		}
		len++;
	}
	return(len);
}

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if(c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
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
	//free(save);
	return(n_save);
}

int main()
{
	char	*s = "hola\n";
	size_t len;
	
	//printf("%s\n", ft_set_new(s));
	len = len_new(s);
	//printf("%s", ft_set_new(s));
	printf("%s", ft_set_saved(s));
	printf("%zu", len);
	return(0);
}