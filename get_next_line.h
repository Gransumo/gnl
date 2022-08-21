/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:24:09 by gcastro-          #+#    #+#             */
/*   Updated: 2022/07/19 12:24:11 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *save, char *buff);
char	*get_line(char	*save, int fd);
char	*ft_set_new(char *save);
char	*ft_set_saved(char *save);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	len_new(char *save);

#endif
