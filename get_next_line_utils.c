/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:25:23 by gcastro-          #+#    #+#             */
/*   Updated: 2022/07/19 12:25:24 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *save, char *buff)
{
	char	*ptr;
	size_t		i;
	size_t		j;

	if(save == NULL && buff == NULL)
		return (NULL);
	i = 0;
	j = -1;
	ptr = malloc(ft_strlen(save) + ft_strlen(buff) + 1);
	if(ptr == NULL)
		return(NULL);
	while(i < ft_strlen(save))
	{
		ptr[i] = save[i];
		i++;
	}
	while(++j < ft_strlen(buff))
	{
		ptr[i + j] = buff[j];
	}
	ptr[i + j] = '\0';
	free(buff);
	free(save);
	return(ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	x;
	size_t	i;

	i = 0;
	x = ft_strlen ((char *)s);
	while (i < x)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
		i++;
	}
	return (NULL);
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

size_t	len_new(char *save)
{
	size_t	len;

	len = 0;
	if(!save)
		return (0);
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
