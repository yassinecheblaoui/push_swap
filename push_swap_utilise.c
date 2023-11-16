/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:18 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/16 15:28:20 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

long	ft_atoi(const char *str)
{
	int			i;
	int			j;
	long int	nb;

	i = 0;
	j = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	long result = nb * j;
	if (result > INT_MAX || result < INT_MIN)
		ft_protect(1);
	return result;
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
} 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		*sub = '\0';
		return (sub);
	}
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static	int	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] != c)
		j++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0' )
			j++;
		i++;
	}
	return (j);
}

static	int	ft_lenstr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	char	**ft_free(char **tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	j = 0;
	if (!tab)
		return (NULL);
	while (s[i] && j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			tab[j] = ft_substr(&s[i], 0, ft_lenstr(&s[i], c));
			if (!tab[j++])
				return (ft_free(tab, j));
			i += ft_lenstr(&s[i], c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
int	check_double(char **result)
{
	int i;
	int j;

	i = 0;
	while (result[i])
	{
		j = i + 1;
		while (result[j])
		{
			if (ft_atoi(result[i]) == ft_atoi(result[j]))
				ft_protect(2);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_sign(char **result)
{
	int i;
	int j;

	j = 0;
	while(result[j])
	{
		i = 0;
		if (result[j][i] == '-' || result[j][i] == '+')
			i++;
		while (result[j][i])
		{
			if (result[j][i] == '-'|| result[j][i] == '+')
				ft_protect(1);
			i++;
		}
		j++;
	}
}

void check_int(char **str)
{
	int i;
	int j;
	long int nb;

	i = 0;
	while (str[i])
	{
		j = 0;
		nb = ft_atoi(str[i]);
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				ft_protect(1);
			j++;
		}
		i++;
	}
}