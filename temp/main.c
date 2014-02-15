/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:31:28 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/15 20:42:40 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	t_env	env;
	t_cmd	cmd;

	cmd.raw = NULL;
	cmd.exit = 0;	
	env.term = (t_term *)malloc(sizeof(t_term));
	if (term_ini(&env))
	{
		while (!cmd.exit)
		{
			ft_putstr("prompt > ");
			command_get(&env, &cmd);
			ft_putchar('\n');
			printf("command: %s\n", cmd.raw);
		}
	}
	term_close();
	return (0);
}