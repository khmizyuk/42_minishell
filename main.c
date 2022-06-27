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

int	main(int argc, char **argv, char **envp)
{
	char		*readed_line;
	char		*trimmed_readed_line;
	t_tokens	*list_head;

	list_head = NULL;
	exit_status = 0;
	while (1)
	{
		readed_line = readline(">> ");
		if (!ft_strlen(readed_line))
			continue;
		add_history(readed_line);
		trimmed_readed_line = ft_strtrim(readed_line, " ");
		free(readed_line);
		if (!trimmed_readed_line)
			continue;
		list_head = lexer(list_head, trimmed_readed_line, envp);
		// parser();
		// executor();
		free(trimmed_readed_line);
	}
	return(0);
}
        