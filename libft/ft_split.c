/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:31 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/13 20:15:42 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c, size_t len)
{
	size_t	words;
	size_t	i;

	if (len == 0)
		return (0);
	words = 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char		**split_aux(char const *s, char c, size_t len, size_t wcount)
{
	char		**result;
	char		**res;
	size_t		start;
	size_t		end;

	start = 0;
	end = 0;
	if (!(result = (char **)malloc(sizeof(char *) * (wcount + 1))))
		return (NULL);
	res = result;
	while (end < len)
		if (s[end] == c || end + 1 == len)
		{
			end = (end + 1 == len ? len : end);
			if (!(*result = ft_substr(s, start, (end - start))))
				return (NULL);
			result++;
			while (s[end] == c)
				end++;
			start = end;
		}
		else
			end++;
	*result = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	size_t		len;
	size_t		wcount;
	char		**result;

	s = ft_strtrim(s, &c);
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	wcount = count_words(s, c, len);
	result = split_aux(s, c, len, wcount);
	return (result);
}
