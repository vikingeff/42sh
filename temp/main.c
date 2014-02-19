/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:31:28 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 10:42:04 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	t_env	env;
	t_cmd	cmd;
	char 	prompt[] = "$>";

	cmd.raw = NULL;
	cmd.exit = 0;	
	env.term = (t_term *)malloc(sizeof(t_term));		/*to add*/
	if (term_ini(&env))									/*to add*/
	{
		while (!cmd.exit)
		{
			ft_putstr(prompt);
			env.prompt_len = ft_strlen(prompt);			/*to add*/
			env.prompt = ft_strdup(prompt);				/*to add*/
			command_get(&env, &cmd);					/*to change*/
			free(env.prompt);							/*to add*/
			env.prompt = NULL;							/*to add*/
			ft_putchar('\n');
			printf("OUTPUT: %s\n", cmd.raw);
		}
	}
	term_close(&env);									/*to add*/
	return (0);
}