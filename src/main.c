/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:46:47 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 17:51:12 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

pid_t		process_id;

void	ft_print_arg(t_list *arg)
{
	t_list	*dir;
	t_list	*list;

	list = arg;
	while (list)
	{
		printf("commande = %s\n", list->mot);
		printf("synthaxe = %s\n", list->valeure);
		dir = list->dir;
		if (dir)
			printf("	redirection : \n");
		while (dir)
		{
			printf("	direction = %s\n", dir->mot);
			printf("	target = %s\n", dir->valeure);
			dir = dir->next;
		}
		list = list->next;
	}
}

t_list	*ft_parser(char *str)
{
	t_list	*arg;
	int		index;
	int		start;
	char	*tmp;
	char	buf[3];

	buf[1] = 0;
	buf[2] = 0;
	index = 0;
	start = 0;
	arg = NULL;
	while (str[index])
	{
		if ((str[index] == '&' && str[index + 1] == '&') || (str[index] == '|' && str[index + 1] == '|'))
		{
			buf[0] = str[index];
			buf[1] = str[index];
			tmp = ft_strsub(str, start, index - start);
			arg = ft_add_arg(tmp, buf, arg);
			free(tmp);
			buf[1] = 0;
			start = index + 2;
			index++;
		}
		else if (str[index] == ';' || str[index] == '|')
		{
			buf[0] = str[index];
			tmp = ft_strsub(str, start, index - start);
			arg = ft_add_arg(tmp, buf, arg);
			free(tmp);
			start = index + 1;
		}
		index++;
	}
	tmp = ft_strsub(str, start, index - start);
	arg = ft_add_arg(tmp, ";", arg);
	if (tmp)
		free(tmp);
	arg = ft_parser_direct(arg);
	return (arg);
}

void	ft_delete_char(t_cmd *cmd, int index)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strsub(cmd->raw, 0, index);
	tmp2 = ft_strsub(cmd->raw, index + 1, ft_strlen(cmd->raw) - (index + 1));
	free(cmd->raw);
	cmd->raw = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

int		ft_inib(t_cmd *cmd)
{
	int	rule;
	int	index;
	int	inib;

	rule = 0;
	index = 0;
	while (cmd->raw[index])
	{
		if (cmd->raw[index] == '\'' || cmd->raw[index] == '\"')
		{
			if (!rule)
			{
				rule = cmd->raw[index];
				ft_delete_char(cmd, index);
			}
			if (rule == cmd->raw[index])
			{
				rule = 0;
				ft_delete_char(cmd, index);
			}
		}
		if (cmd->raw[index] == '\\' && !rule)
		{
			ft_delete_char(cmd, index);
			cmd->raw[index] = - 1 * cmd->raw[index];
		}
		else if (rule)
			cmd->raw[index] = - 1 * cmd->raw[index];
		index++;
	}
	if (rule)
		return (1);
	return (0);
}

int		main(int ac, char **environ)
{
	t_env	env;
	t_dir	dir;
	t_cmd	cmd;
	int		ret;
	t_list	*arg;

	arg = NULL;
	env.raw = environ;
	process_id = -2;
	ft_signal();
	if (ac > 1)
		return (error(0, NULL));
	if (shell_ini(&cmd, &dir, &env))
		return (-1);
	while (!cmd.exit)
	{
		prompt_display(&dir);
		if (command_get(&cmd) > 0)
		{
			if (ft_inib(&cmd))
				continue ;
			if (arg)
				ft_free_arg(arg);
			arg = ft_parser(cmd.raw);
			ft_print_arg(arg);
			if (ft_launcher(arg, &cmd, &env, &dir) == -1)
			{
				printf("ret\n");
				return (0);
			}
		}
		else
			cmd.exit = 1;
	}
	return (0);
}
