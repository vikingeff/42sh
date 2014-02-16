/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 12:02:54 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/15 19:50:14 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_fd_tmp(char *str)
{
	char	*line;
	int		fd;

	fd = open("/tmp/sh.heredoc", O_RDWR| O_TRUNC | O_CREAT, 0666);
	ft_putstr("? ");
	while (get_next_line(0, &line) && ft_strcmp(str, line))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_putstr("? ");
	}
	close(fd);
	fd = open("/tmp/sh.heredoc", O_RDONLY);
	return (fd);
}

static int		ft_open(char *str, int select)
{
	int	fd;

	if (select == 1)
		fd = open(str, O_WRONLY | O_APPEND | O_CREAT, 0666);
	else if (select == 0)
		fd = open(str, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	else if (select == 2)
		fd = open(str, O_RDONLY);
	else if (select == 3)
		fd = ft_fd_tmp(str);
	if (fd == -1)
	{
		ft_putstr("open error :");
		ft_putstr(str);
		ft_putstr("\n");
	}
	return (fd);
}

int				ft_get_fd(t_list *dir)
{
	int	fd;
	int	select;

	select = 0;
	if (dir == NULL)
		return (0);
	if (ft_strcmp(dir->mot, ">>") == 0)
		select = 1;
	else if (ft_strcmp(dir->mot, "<") == 0)
		select = 2;
	else if (ft_strcmp(dir->mot, "<<") == 0)
		select = 3;
	fd = ft_open(dir->valeure, select);
	return (fd);
}