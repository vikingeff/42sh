/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:31:28 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:21:07 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	t_env	env;
	t_cmd	cmd;

	cmd.raw = NULL;
	cmd.exit = 0;	
	env.term = (t_term *)malloc(sizeof(t_term));		/*to add*/
	if (term_ini(&env))									/*to add*/
	{
		while (!cmd.exit)
		{
			ft_putstr("prompt > ");
			command_get(&env, &cmd);					/*to change*/
			ft_putchar('\n');
			printf("command: %s\n", cmd.raw);
		}
	}
	term_close(&env);									/*to add*/
	return (0);
}