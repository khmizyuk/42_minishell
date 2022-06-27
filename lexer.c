/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:54:41 by nnelson           #+#    #+#             */
/*   Updated: 2022/06/23 21:18:58 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tokens	*lst_get_last_elem(t_tokens *list) //возврат позиции последнего элемента в списке
{
	if (!list)
		return (NULL);
	if (!list->next)
		return (list);
	else
	{
		while (list->next)
			list = list->next;
		return (list);
	}
}

static t_tokens	*lst_init_new_elem(char *value) //инициализация нового элемента списка
{
	t_tokens	*lst_new_elem;

	lst_new_elem = malloc(sizeof(t_tokens));
	if (lst_new_elem && value)
	{
		lst_new_elem->token = value;
		lst_new_elem->next = NULL;
		printf("token: %s\n", value);
		return (lst_new_elem);
	}
	return NULL;
}

static t_tokens *lst_add_back(t_tokens *list_head, t_tokens *elem) //добавляет новый элемент списка в его конец
{
	t_tokens	*elem_to_add;

	if (!list_head)
		list_head = elem;
	else
	{
		elem_to_add = lst_get_last_elem(list_head);
		elem_to_add->next = elem;
	}
	return (list_head);
}

t_tokens	*lexer(t_tokens *list_head, char *readed_line, char **envp)
{
	char		*token;
	char 		*uncovered_token;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < ft_strlen(readed_line))
	{
		j = 0; // j - длина слова для обрезания
		while (readed_line[i] && ft_isspace(readed_line[i])) //скип лишних пробелов на случай, если после обрезания слова за ним следуют много лишних пробелов
			i++;
		while (readed_line[i + j] && !ft_isspace(readed_line[i + j])) //считается длина слова для обрезания
			j++;
		token = ft_substr(readed_line, i, j); //обрезание слова из readed_line: начиная с i-го элемента длиной в j символов
		uncovered_token = uncover_token(token, envp);
		free(token);
		list_head = lst_add_back(list_head, lst_init_new_elem(uncovered_token)); //добавляем обрезанное слово в список
		free(uncovered_token);
		i += j;
		if (readed_line[i])
			list_head = lst_add_back(list_head, lst_init_new_elem(" ")); //добавляем пробел в список
	}
	return (list_head);
}
