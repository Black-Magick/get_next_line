/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:03:13 by remanuel          #+#    #+#             */
/*   Updated: 2023/01/19 13:18:16 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
	Iterates on a string until it finds the NULL character or a newline character
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
/*
	Similar to the "normal" strjoin but if it finds a newline char in the buffer
	it only joins that far
*/

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
	Iterates on the buffer everytime its called in the gnl 
	function and erasesthe read buffer by filling it with 
	NULL chars while also looking for a newline char in the buffer.
	If it finds one it returns true(1) and the gnl while loop is exited
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
