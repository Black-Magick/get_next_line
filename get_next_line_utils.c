/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:34:07 by remanuel          #+#    #+#             */
/*   Updated: 2023/01/11 11:12:13 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	This function iterates on a string until it finds the terminating NULL character.
	If it finds a newline character the position of the index is increased by 1(one) to account for it.
	The return value is the amount of characters found in the string, either up until
	and including the newline character (if it finds one), or, until the terminating NULL character.
*/
size_t	n_strlen(char *str)
{
	int	index;
	
	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0' && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	return (index);
}


char	*n_strjoin(char *return_line, char *buffer)
{
	size_t	index;
	char	*new_line;
	
	index = 0;
	new_line = malloc(n_strlen(return_line) + n_strlen(buffer) + 1);
	if (!new_line)
		return (NULL);
	while (return_line != NULL && return_line[index] != '\0')
	{
		new_line[index] = return_line[index];
		index++;
	}
	free(return_line);
	while (*buffer != '\0')
		{
		new_line[index++] = *buffer;
			if (*buffer++ == '\n')
				break ;
		}
	new_line[index] = '\0';
	return (new_line);
}
/*
	This function 
*/
int	n_remover(char *buffer)
{
	int	line_check;
	int	index;
	int	index_2;
	
	line_check = 0;
	index = 0;
	index_2 = 0;
	while (buffer[index] != '\0')
	{
		if (line_check != 0)
			buffer[index_2++] = buffer[index];
		if (buffer[index] == '\n')
			line_check = 1;
		buffer[index++] = '\0';
	}
	return (line_check);
}