/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:45:19 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/26 19:30:54 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_find_rule(char *str, int index)
{
	if ((index - 1) > 0 && (str[index - 1] == '|'
		|| str[index - 1] == ';' || str[index - 1] == '`'))
		return (1);
	if ((index - 2) > 0)
		if ((str[index - 1] == '&' && str[index - 2] == '&')
			|| (str[index - 1] == '|' && str[index - 2] == '|'))
		return (1);
	if ((index - 1) > 0 && str[index - 1] == '|')
		return (1);
	return (0);
}

int		ft_find_status(char *str, int begin)
{
	int	rule;
	int index;

	index = 0;
	rule = 1;
	while (str[index] && index <= begin)
	{
		if (!rule)
			rule = ft_find_rule(str, index);
		if (index == 0 || ft_special_char(str[index - 1]))
		{
			if (begin == index)
			{
				printf("checking %c\n", str[index]);
				return (rule);
			}
			else
				rule = 0;
		}
		index++;
	}
	printf("checking %c\n", str[index]);
	return (rule);
}

int		get_begin(char *str, int cursor)
{
	int	index;

	index = cursor;
	while (index >= 0)
	{
		if (ft_special_char(str[index]))
			return (index + 1);
		index--;
	}
	return (0);
}

char	*clean_str(char *base)
{
	char	**tmp;
	int		index;
	char	*result;
	char	*inter;

	result = NULL;
	inter = NULL;
	tmp = ft_strsplit_all(base);
	index = -1;
	while (tmp[++index])
	{
		inter = ft_strdup(result);
		free(result);
		result = str_join_chr(inter, tmp[index], ' ');
		free(inter);
	}
	free(base);
	array2d_free(tmp);
	return (result);
}

char	*return_completion(glob_t *globbuf, char *tmp, char *ret)
{
	free(tmp);
	globfree(globbuf);
	return (ret);
}

char	*fill_completion_arg(t_cmd *cmd, char *str, int flag)
{
	glob_t		globbuf;
	char		*ret;
	char		*tmp;

	tmp = ft_strjoin(str, "*");
	if (glob(tmp, GLOB_MARK | GLOB_ERR, NULL, &globbuf))
		return (return_completion(&globbuf, tmp, NULL));
	ret = ft_strdup(globbuf.gl_pathv[cmd->comp]);
	if (!flag)
		cmd->comp = 0;
	else
		cmd->comp++;
	if (flag && cmd->comp == globbuf.gl_pathc)
		cmd->comp = 0;
	return (return_completion(&globbuf, tmp, ret));
}

char	*fill_completion_bin(t_cmd *cmd, char *str, int flag)
{
	glob_t		globbuf;
	char		*ret;
	char		*tmp;
	int			index;
	char		*concat;
	char		**table;

	index = -1;
	tmp = ft_strjoin(str, "*");
	while (cmd->paths[++index])
	{
		concat = str_join_chr(cmd->paths[index], tmp, '/');
		if (index == 0)
			glob(concat, GLOB_MARK | GLOB_ERR, NULL, &globbuf);
		else
			glob(concat, GLOB_APPEND | GLOB_MARK | GLOB_ERR, NULL, &globbuf);
		free(concat);
	}
	if (globbuf.gl_pathc == 0)
		return (return_completion(&globbuf, tmp, NULL));
	table = ft_strsplit(globbuf.gl_pathv[cmd->comp], '/');
	ret = ft_strdup(table[ft_tablen(table) - 1]);
	if (!flag)
		cmd->comp = 0;
	else
		cmd->comp++;
	if (flag && cmd->comp == globbuf.gl_pathc)
		cmd->comp = 0;
	return (return_completion(&globbuf, tmp, ret));
}

char	*fill_completion(t_cmd *cmd, char *str, int status, int flag)
{
	if (cmd->comp == -1)
		cmd->comp++;
	if (status == 0)
		return (fill_completion_arg(cmd, str, flag));
	else
		return (fill_completion_bin(cmd, str, flag));
}

void	completion(t_cmd *cmd, t_cur *cursor, t_char **list, int flag)
{
	int		status;
	int		begin;
	char	*tmp;
	char	*word;
	char	*end;
	char	*final;
	int 	i;
	char	*trash;

	final = NULL;
	if (!*list || ft_special_char((*list)->c))
		return ;
	if (cmd->s_cursor == -1)
		cmd->s_cursor = cursor->x - 1;
	while ((*list)->next)
		k_right(cmd, cursor, list);
	if (cmd->actual == NULL)
	{
		cmd->actual = edit_list_to_str(*list, cmd, cursor);
		printf("\nreset is done\n");
	}
	else
	{
		trash = edit_list_to_str(*list, cmd, cursor);
		free(trash);
	}
	begin = get_begin(cmd->actual, cmd->s_cursor);
	printf("\nbegin %d\n", begin);
	printf("cursor %d\n", cmd->s_cursor);
	printf("ACTUAL CMD %s\n", cmd->actual);
	printf("point %c\n", cmd->actual[cmd->s_cursor]);	

	status = ft_find_status(cmd->actual, begin);

	printf("status %d\n", status);

	word = ft_strsub(cmd->actual, begin, cmd->s_cursor - begin + 1);
		printf("\nword : %s\n", word);
	end = ft_strsub(cmd->actual, cmd->s_cursor + 1, ft_strlen(cmd->actual) - cmd->s_cursor);
	printf("\nend : %s\n", end);
	tmp = ft_strsub(cmd->actual, 0, begin);
	printf("begin %s\n", tmp);
	final = fill_completion(cmd, word, status, flag);
	printf("completion %s\n", final);
	if (!final)
		final = ft_strdup(word);
	printf("completion after if %s\n", final);
	word = ft_strjoin(tmp, final);
	word = ft_strjoin(word, end);
	printf("chaine finale %s\n", word);
	i = -1;
	printf("cord final %s\n", word);
	printf("cursor %d\n", cursor->x);
	*list = NULL;
	while (word[++i])
	{
		*list = edit_char_add(*list, word[i], cursor, cmd);
		(*list)->mirror = 0;
	}
		printf("cursor X %d\n", cursor->x);
}
