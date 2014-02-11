/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:59:48 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 16:33:32 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		cmd_format(t_cmd *cmd, int *option);
static t_var	*env_lst_copy(t_env *env);
static void		env_modify(t_cmd *cmd, t_cmd *c_cmd, t_env *c_env);
static void		cmd_clean(t_cmd *cmd);

/*
** if no arguments, sh_env display the environnement variables
** if arguments are env modifcation, creates a copy of current env list 
** to apply changes for the potential following command execution
** if a command is found in the arguments, the command will be executed with
** a temporary environnement set.
*/

int				sh_env(t_cmd *cmd, t_env *env)
{
	int		i;
	/*int		option;
	t_env	c_env;
	t_cmd	c_cmd;
*/
	i = -1;
	while (cmd->env[++i])
		printf("%s\n", cmd->env[i]);
	/*option = 0;
	if (cmd_format(cmd, &option))
		return (-1);
	c_env.var = (option) ? NULL : env_lst_copy(env);
	c_env.nb = (option) ? 0 : env->nb;
	c_cmd.paths = cmd->paths;
	env_modify(cmd, &c_cmd, &c_env);
	cmd_clean(cmd);
	c_cmd.split = cmd->split;
	if (!option)
		c_cmd.env = env_list_to_array(c_env.var, c_env.nb);
	else
		c_cmd.env = env_list_to_array(c_env.var, c_env.nb + 1);
	if (c_cmd.split[0])
		return (command_execute(&c_cmd, &c_env, NULL));
	i = -1;
	while (c_cmd.env[++i])
		ft_putendl(c_cmd.env[i]);*/
	return (0);
}

/*
** check if the format of the command is valid and define if the option [-i]
** is present and if sh_env needs to display the variables or not.
*/

static int		cmd_format(t_cmd *cmd, int *option)
{
	int			i;

	i = 0;
	while (cmd->split[i] && i < 2)
	{
		if (cmd->split[i][0] == '-')
		{
			if (cmd->split[i][1] == 'i')
				*option = 1;
			else
				return (error(3, &cmd->split[1][1]));
		}
		i++;
	}
	return (0);
}

/*
** make a copy of env list for further temporary modifcation
*/

static t_var	*env_lst_copy(t_env *env)
{
	t_var		*list;
	t_var		*start;
	t_var		*p_var;

	list = NULL;
	start = NULL;
	p_var = env->var;
	while (p_var)
	{
		if (env_list_add(&list, &start))
			return (NULL);
		list->name = ft_strdup(p_var->name);
		list->value = ft_strdup(p_var->value);
		p_var = p_var->next;
	}
	return (start);
}

/*
** use the copy env list and change or add it with user's
** arguments
*/

static void		env_modify(t_cmd *cmd, t_cmd *c_cmd, t_env *c_env)
{
	int			i;
	int			len;

	i = 0;
	while (cmd->split[++i])
	{
		len = 0;
		while (cmd->split[i][len] && cmd->split[i][len] != '=')
			len++;
		if (len < ft_strlen(cmd->split[i]))
		{
			c_cmd->split = (char**)malloc(sizeof(char*) * 4);
			c_cmd->split[0] = ft_strdup("setenv");
			c_cmd->split[1] = ft_strsub(cmd->split[i], 0, len);
			c_cmd->split[2] = ft_strsub(cmd->split[i], len + 1,
							(ft_strlen(cmd->split[i]) - (len + 1)));
			c_cmd->split[3] = NULL;
			if (c_env->var)
				sh_setenv(c_cmd, c_env);
			else
				env_list_create(c_cmd, c_env);
		}
	}
}

/*
** put in front of the split array all command for execve use
*/

static void		cmd_clean(t_cmd *cmd)
{
	int			i;
	int			j;
	int			index;
	int			copy;
	int			len;

	i = index = 0;
	while (cmd->split[++i])
	{
		j = -1;
		copy = 1;
		while (cmd->split[i][++j])
			if ((cmd->split[1][0] == '-' && cmd->split[1][1] == 'i')
				|| cmd->split[i][j] == '=')
				copy = 0;
		if (copy)
		{
			len = ft_strlen(cmd->split[i]);
			free(cmd->split[index]);
			cmd->split[index] = (char *)malloc(sizeof(char) * (len + 1));
			cmd->split[index] = ft_strdup(cmd->split[i]);
			index++;
		}
	}
	cmd->split[index] = NULL;
}
