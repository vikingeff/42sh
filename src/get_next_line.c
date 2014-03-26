/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:56:26 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 00:23:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/uio.h>
#include "shell.h"

#define BUFF_SIZE 2

static int		no_leak_exit(char *memory, int ret)
{
	free(memory);
	return (ret);
}

static char		*string_join(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = malloc(sizeof(*r) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2 && s2[j])
	{
		r[i] = s2[j];
		++i;
		++j;
	}
	r[i] = 0;
	return (r);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t		sz;
	static char	*mem;
	char		*tmp;
	char		*endl;
	char		buff[BUFF_SIZE + 1] = {'\0'};

	if (line && mem && (tmp = mem) && (endl = ft_strchr(mem, '\n')))
	{
		if (!(*line = ft_strsub(mem, 0, endl - mem))
			|| !(mem = ft_strsub(endl + 1, 0, ft_strlen(endl + 1))))
			return (no_leak_exit(mem, -1));
		free(tmp);
		return (1);
	}
	else if ((sz = 1) && line && (sz = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((!mem && !(mem = ft_strnew(0))) || ((tmp = mem) && 0)
			|| !(mem = string_join(mem, buff)))
			return (no_leak_exit(mem, -1));
		free(tmp);
		return (get_next_line(fd, line));
	}
	if (sz == -1 || !line || !mem || ((*line = mem) && (mem = NULL)))
		return (no_leak_exit(mem, sz = (sz == -1 || !line) ? -1 : 0));
	return (no_leak_exit(tmp = **line ? NULL : *line, sz = **line ? 1 : 0));
}
