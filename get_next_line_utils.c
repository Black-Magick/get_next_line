/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:34:07 by remanuel          #+#    #+#             */
/*   Updated: 2023/01/04 11:17:16 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Retorna a quantidade de caracteres ate encontrar caracter nulo
	ou um newline. index++ no fim para adicionar o valor do newline ao return
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

int	n_cleaner(char *buffer)
{
	int	line_check;
	int	index;
	int	index_2;
	
	line_check = 0;
	index = 0;
	index_2 = 0;
	while (buffer[index] != '\0')
	{
		if (line_check)
			buffer[index_2++] = buffer[index];			
		if (buffer[index] == '\n')
			line_check = 1;
		buffer[index++] = '\0';
	}
	return (line_check);
}