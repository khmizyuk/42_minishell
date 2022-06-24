/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:10:49 by nnelson           #+#    #+#             */
/*   Updated: 2022/06/23 21:14:33 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

#include <stdio.h>
#include <unistd.h>

#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

typedef struct s_tockens
{
	char				*tocken;
	// char				*type_of_tocken; //separator (is_space), files, commands, flag, command_arg, quotes (double and single), redirects (<< < > >>), pipe, IF_OR(&&, ||, ;) ??mixed??
	struct	s_tockens	*next;
}	t_tockens;

t_tockens	*lexer(char *readed_line);

//list_of_all_tockens
//list_group
	//left_group -> execute
	//right_group -> execute