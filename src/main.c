/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <joppe@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/18 23:07:10 by joppe         #+#    #+#                 */
/*   Updated: 2020/10/19 00:43:36 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "constants.h"
#include "ft_matrix.h"
#include "ft_file.h"
#include "ft_string.h"
#include "ft_io.h"

#include <stdlib.h>
#include <stdio.h>

char	**get_dictionary(void)
{
	char		**dictionary;
	uint64_t	i;

	dictionary = ft_split_file(DICTIONARY_FILE, DICTIONARY_FILE_SEPERATOR);
	i = 0;
	while (dictionary[i] != NULL)
	{
		ft_strsort(dictionary[i]);
		i++;
	}
	return (dictionary);
}

void	search(char *word_part, char **dictionary_sorted, char **dictionary)
{
	uint64_t	word_part_i;
	uint64_t	dictionary_i;
	uint64_t	word_i;
	char		*word;
	bool		match;
	uint64_t	words_printed;

	word_part_i = 0;
	word_i = 0;
	words_printed = 0;
	dictionary_i = 0;
	while (dictionary_sorted[dictionary_i] != NULL)
	{
		word = dictionary_sorted[dictionary_i];
		word_i = 0;
		word_part_i = 0;
		match = false;
		while (word[word_i] != '\0')
		{
			if (word_part[word_part_i] == word[word_i])
				word_part_i++;
			if (word_part[word_part_i] == '\0')
			{
				match = true;
				break ;
			}
			word_i++;
		}
		if (match)
		{
			if (words_printed < MAX_POSSIBILITIES)
			{
				ft_putstr(dictionary[dictionary_i]);
				ft_putstr("\n");
				words_printed++;
			}
			else
			{
				ft_putstr("...\n");
				break ;
			}

		}
		dictionary_i++;
	}
}

int32_t main(int32_t argc, char **argv)
{
	char	*word_part;
	char	**dictionary;
	char	**dictionary_sorted;
	uint64_t dictionary_length;

	if (argc != 2)
		return (1);
	dictionary = ft_split_file(DICTIONARY_FILE, DICTIONARY_FILE_SEPERATOR);
	dictionary_length = 0;
	while (dictionary[dictionary_length] != NULL)
		dictionary_length++;
	// printf("dictionary_length %lu\n", dictionary_length);
	dictionary_sorted = get_dictionary();
	word_part = ft_strdup(argv[1]);
	ft_strsort(word_part);

	search(word_part, dictionary_sorted, dictionary);

	// free(word_part);
	// ft_free_matrix((void **)dictionary);
	// ft_free_matrix((void **)dictionary_sorted);
	return (0);
}
