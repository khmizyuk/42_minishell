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

t_tockens	*lst_get_last_elem(t_tockens *list) //возврат позиции последнего элемента в списке
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

t_tockens	*lst_init_new_elem(char *value) //инициализация нового элемента списка
{
	t_tockens	*lst_new_elem;

	lst_new_elem = (t_tockens *)malloc(sizeof(t_tockens));
	if (!lst_new_elem)
		//malloc perror
	lst_new_elem->tocken = value;
	lst_new_elem->next = NULL;
	return (lst_new_elem);
}

void	lst_add_back(t_tockens **list_head, t_tockens *elem) //добавляет новый элемент списка в его конец
{
	t_tockens	*elem_to_add;

	if (*list_head == NULL)
		*list_head = elem;
	else
	{
		elem_to_add = lst_get_last_elem(*list_head);
		elem_to_add->next = elem;
	}
}

t_tockens	*lexer(char *readed_line)
{
	t_tockens	*list_head;
	char		*tocken;
	size_t		i;
	int			j;

	list_head = NULL;
	i = 0;
	while (ft_isspace(readed_line[i]) && readed_line[i]) //скип пробелов в начале строки до запуска основного цикла
			i++;
	while (i < ft_strlen(readed_line))
	{
		j = 0; // j - длина слова для обрезания
		while (readed_line[i] && ft_isspace(readed_line[i])) //скип лишних пробелов на случай, если после обрезания слова за ним следуют много лишних пробелов
			i++;
		while (readed_line[i] && !ft_isspace(readed_line[i])) //считается длина слова для обрезания
			j++;
		tocken = ft_substr(readed_line, i, j); //обрезание слова из readed_line: начиная с i-го элемента длиной в j символов
		lst_add_back(&list_head, lst_init_new_elem(tocken)); //добавляем обрезанное слово в список
		free(tocken);
		i += j; //перевод индекса i, который находился на 1м символе обрезанного слова на позицию пробела, находящийся после обрезанного слова
		lst_add_back(&list_head, lst_init_new_elem(&readed_line[i])); //добавляем пробел в список
	}
	return (list_head);
}
