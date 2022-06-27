#include "minishell.h"

int	are_quotes_closed(char *token, size_t *i)
{
	size_t	j;

	j = *i;
	if (token[j] == '\'')
	{
		while (token[j])
		{
			j++;
			if (token[j] == '\'')
				return (1);
		}
	}
	else if (token[j] == '\"')
	{
		while (token[j])
		{
			j++;
			if (token[j] == '\"')
				return (1);
		}
	}
	return (0);
}

char	*process_env(char *token, size_t *i, char *uncovered_token, char **envp)
{
	char *temp;

	*i += 1;
	if (token[*i] == '?')
	{
		//напечатать через ft_itoa значение переменной, которая будет хранить process exit status (в случае ошибки не 0 и обновлять после каждой команды)
		temp = uncovered_token;
		uncovered_token = ft_strjoin(uncovered_token, ft_itoa(exit_status));
		free(temp);
	}
	else if (ft_isalpha(token[*i]) || token[*i] == '_')
	{
		//process_key(token, i, uncovered_token, envp);
		//идти по строке либо до конца, либо до ' или " или пробела
	}
	else
	{
		//обработать запись символа $
		//он один или в конце токена
		//if !token[*i] -> записать в итог $
	}
	return (uncovered_token);
}

char	*process_single_quotes(char *token, size_t *i, char *uncovered_token) //abc"ab""gjhsdfj"
{
	char	*temp;
	if (are_quotes_closed(token, i))
	{
		*i += 1;
		while(token[(*i)] && token[(*i)] != '\'')
		{
			temp = uncovered_token;
			uncovered_token = ft_append(uncovered_token, token[(*i)]);
			*i += 1;
			free(temp);
		}
		*i += 1;
	}
	else
	{
		printf("!!!\n");
		*i = ft_strlen(token);
		free(uncovered_token);
		uncovered_token = NULL;
	}
	return (uncovered_token);
}

char	*process_double_quotes(char *token, size_t *i, char *uncovered_token, char **envp)
{
	char	*temp;
	if (are_quotes_closed(token, i))
	{
		*i += 1;
		while(token[(*i)] && token[(*i)] != '\'')
		{
			temp = uncovered_token;
			if (token[*i] != '$')
				uncovered_token = ft_append(uncovered_token, token[(*i)]);
			else
				uncovered_token = process_env(token, i, uncovered_token, envp);
			*i += 1;
			free(temp);
		}
		*i += 1;
	}
	else
	{
		printf("!!!\n");
		*i = ft_strlen(token);
		free(uncovered_token);
		uncovered_token = NULL;
	}
	return (uncovered_token);
}

char	*uncover_token(char *token, char **envp)
{
	char	*uncovered_token;
	char	*temp;
	size_t	i;

	i = 0;
	uncovered_token = ft_strdup("");
	while (token[i])
	{
		if (ft_isalpha(token[i]))
		{
			temp = uncovered_token;
			uncovered_token = ft_append(uncovered_token, token[i]);
			i++;
			free(temp);
			// вызовем функцию для добавления буковки в итоговую стороку
		}
		else if (token[i] == '$')
		{
			uncovered_token = process_env(token, &i, uncovered_token, envp);
		}
		else if (token[i] == '\'')
		{
			uncovered_token = process_single_quotes(token, &i, uncovered_token);
			// проин=гнорируем нулевой символ
		}
		else if (token[i] == '\"')
		{
			uncovered_token = process_double_quotes(&token[i], &i, uncovered_token, envp);
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
				// раскрывать $ $ENV $?
				// записывать без ковычек
				// проверить парные ковычки
}

//execve()