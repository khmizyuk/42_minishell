#include "minishell.h"

char *uncover_token(char *token)
{
	char	*uncovered_token;
	size_t	i;

	i = 0;
	uncovered_token = ft_strdup("");
	while (token[i])
	{
		if (ft_isalpha(token[i]))
			// вызовем функцию для добавления буковки в итоговую стороку
		else if (token[i] == '$')
		{

		}
		else if (token[i] == '\'')
		{
			process_single_quote(&token[i], &uncovered_token, &i)
			// проин=гнорируем нулевой символ
		}
		else if (token[i] == '\"')
		{
			process_double_quote(&token[i], &uncovered_token, &i)
		}
	}
	return (uncovered_token);

	//сравнить с фуннкциями

	//если не функция
		//идти по строке
			// если буква - дальше
			// если одинарная ковычка - просто убрать ковычки
				// проверить парные ковычки
			// если двойные
				// раскрывать $ $$ $ENV \ $?
				// записывать без ковычек
				// проверить парные ковычки
}

execve()