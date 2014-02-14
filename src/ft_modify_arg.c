/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 18:47:02 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/12 19:32:07 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_get_result(char *str)
{
	int	index;

	if (str[0] == '>' || str[0] == '<')
	str++;
	while (str[index])
	{
		if (str[index] == '>' || str[index] == '<' || str[index] == '|')
			return (ft_strsub(str, 0, index));
		index++;
	}
	return (ft_strdup(str));
}

char	*ft_modify_arg(t_list *arg, int index, int mode)
{
	char	**tmp;
	char	*str;
	char	*result;
	char	*begin;
	char	*clone;

	str = arg->mot;
	if (mode == 1)
		begin = ft_strsub(str, 0, index - 1);
	else
		begin = ft_strsub(str, 0, index);
	while (index-- != -1)
		str++;
	tmp = ft_strsplit_all(str);
	if (tmp[0][1] != '\0')
		result = ft_get_result(tmp[0]);
	else
		result = ft_get_result(tmp[1]);
	while (*str == ' ' || *str == '\t' || *str == '\v')
		str++;
	while (++index < (int)ft_strlen(result) - 1)
		str++;
	clone = ft_strdup(str);
	if (arg->mot)
		free(arg->mot);
	arg->mot = str_join_chr(begin, clone, ' ');
	free(begin);
	free(clone);
	array2d_free(tmp);
	return (result);
}