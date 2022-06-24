/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:57 by nnelson           #+#    #+#             */
/*   Updated: 2022/06/23 21:15:56 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*readed_line;
	t_tockens	*tockens_list;

	while (1)
	{
		readed_line = readline(">> ");
		if (!ft_strlen(readed_line))
			continue;
		add_history(readed_line);
		tockens_list = lexer(readed_line);
		// parser();
		// executor();
		free(readed_line);
	}
	return(0);
}
        