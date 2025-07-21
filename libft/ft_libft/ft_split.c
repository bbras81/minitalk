/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:04:11 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:57 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_free(char **res);
static int	word_count(char const *s, char c);

/**
 * @brief Splits a string into an array of strings using a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return char** An array of strings, NULL-terminated.
 */
char	**ft_split(const char *s, char c)
{
	size_t	counter;
	size_t	counter_res;
	size_t	start_word;
	char	**res;

	res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!res || !s)
		return (NULL);
	counter = 0;
	counter_res = 0;
	while (s[counter] != '\0')
	{
		while (s[counter] == c)
			counter++;
		start_word = counter;
		while (s[counter] != c && s[counter] != '\0')
			counter++;
		if (start_word < counter)
		{
			res[counter_res] = ft_substr(s, start_word, counter - start_word);
			if (res[counter_res++] == NULL)
				return (ft_free(res), NULL);
		}
	}
	return (res[counter_res] = NULL, res);
}

static void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

static int	word_count(char const *s, char c)
{
	size_t	counter;
	size_t	counter_wrd;
	size_t	trigger;

	counter = 0;
	counter_wrd = 0;
	trigger = 0;
	while (s[counter])
	{
		if (s[counter] != c && trigger == 0)
		{
			trigger = 1;
			counter_wrd++;
		}
		else if (s[counter] == c)
		{
			trigger = 0;
		}
		counter++;
	}
	return (counter_wrd);
}
