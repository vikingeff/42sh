/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:59:48 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/12 17:17:31 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		cmd_format(t_cmd *cmd, int *option);
static t_var	*env_lst_copy(t_env *env);
static void		ft_modify_env(char *str, t_env *c_env);
static void		ft_put_env(t_cmd *c_cmd, t_env *c_env, t_dir *dir);
static int		ft_get_i(t_cmd *cmd, int i, t_env *c_env, t_cmd *c_cmd);

/*
** if no arguments, sh_env display the environnement variables
** if arguments are env modifcation, creates a copy of current env list 
** to apply changes for the potential following command execution
** if a command is found in the arguments, the command will be executed with
** a temporary environnement set.
*/

void			ft_free_c_env(t_env *c_env, t_cmd *c_cmd, t_dir *dir)
{
	t_var	*tmp;

	tmp = NULL;
	array2d_free(c_cmd->env);
	array2d_free(c_cmd->paths);
	while (c_env->var)
	{
		tmp = c_env->var->next;
		free(c_env->var->name);
		free(c_env->var->value);
		free(c_env->var);
		c_env->var = tmp;
	}
	c_env->var = NULL;
	free(dir->home);
	free(dir->user);
}

char			**ft_tab_dup(char **tab)
{
	char	**newtab;
	int		index;
	int		size;

	size = ft_tablen(tab);
	index = 0;
	if (!(newtab = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (index < size)
	{
		newtab[index] = ft_strdup(tab[index]);
		index++;
	}
	newtab[index] = NULL;
	return (newtab);
}

int				sh_env(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int			option;
	t_env		c_env;
	t_cmd		c_cmd;
	t_dir		c_dir;
	int			i;

	option = 0;
	if (cmd_format(cmd, &option))
		return (-1);
	c_env.var = NULL;
	c_env.nb = 1;
	c_cmd.paths = NULL;
	c_dir.home = NULL;
	c_dir.user = NULL;
	if (option != 1)
	{
		c_env.var = env_lst_copy(env);
		c_env.nb = env->nb;
		c_cmd.paths = ft_tab_dup(cmd->paths);
	}
	i = option + 1;
	i = ft_get_i(cmd, i, &c_env, &c_cmd);
	if (i < ft_tablen(cmd->split))
	{
		c_cmd.split = cmd->split + i;
		command_execute(&c_cmd, &c_env, &c_dir);
		ft_free_c_env(&c_env, &c_cmd, &c_dir);
		return (0);
	}
	ft_put_env(&c_cmd, &c_env, &c_dir);
	return (0);
}

static int	ft_get_i(t_cmd *cmd, int i, t_env *c_env, t_cmd *c_cmd)
{
	while (cmd->split[i] && ft_strchr(cmd->split[i], '='))
		ft_modify_env(cmd->split[i++], c_env);

	c_cmd->env = env_list_to_array(c_env->var, c_env->nb);
	return (i);
}

/*
** check if the format of the command is valid and define if the option [-i]
** is present and if sh_env needs to display the variables or not.
*/

static int		cmd_format(t_cmd *cmd, int *option)
{
	if (cmd->split[1] && cmd->split[1][0] == '-')
	{
		if (cmd->split[1][1] == 'i')
			*option = 1;
		else
			return (error(3, &cmd->split[1][1]));
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

static void		ft_modify_env(char *str, t_env *c_env)
{
	t_cmd	cmd;
	char	**tmp;
	int		len;

	cmd.env =  env_list_to_array(c_env->var, c_env->nb);
	len = ft_strlen(str) - (ft_strlen(ft_strchr(str, '=')));
	cmd.split = (char**)malloc(sizeof(char*) * 4);
	cmd.split[0] = ft_strdup("setenv");
	cmd.split[1] = ft_strsub(str, 0, len);
	cmd.split[2] = ft_strsub(str, len + 1, ft_strlen(str) - len - 1);
	cmd.split[3] = NULL;
	sh_setenv(&cmd, c_env);
	array2d_free(cmd.split);
	array2d_free(cmd.env);
}

static void		ft_put_env(t_cmd *c_cmd, t_env *c_env, t_dir *dir)
{
	int	i;

	i = 0;
	while (c_cmd->env[i])
	{
		ft_putendl(c_cmd->env[i]);
		i++;
	}
	ft_free_c_env(c_env, c_cmd, dir);
}


