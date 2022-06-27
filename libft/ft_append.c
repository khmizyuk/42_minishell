#include "libft.h"
//#include "stdio.h"

char	*ft_append(char const *s1, char const c)
{
	int		i;
	char	*s;

	if (!s1 || !c)
		return (NULL);
	i = 0;
	s = malloc(ft_strlen(s1) + 2);
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = c;
	i++;
	s[i] = '\0';
	return (s);
}

//int	main()
//{
//	printf("str after append: %s\n", ft_append("tw", 'o'));
//}
