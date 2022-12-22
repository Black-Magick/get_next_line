/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:34:12 by remanuel          #+#    #+#             */
/*   Updated: 2022/12/22 17:07:45 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Get next line, tem de levar protecao para buffersize < 1
	e valores invalidos de read (qualquer um deles < 0)
	Nesse caso preencher o buffer estatico com zeros e retornar NULL
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*return_line;
	int			index;
	
	index = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0 ,0) < 0)
	{
		while(buffer[index])
			buffer[index++] = 0;
		return (NULL);
	}
	return_line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		return_line = n_strjoin(return_line, buffer);
			if (n_cleaner(buffer))
				break ;
	}
	return (return_line);
}

 int main()
{
	int fd = 0;
	char *line;
	fd = open("./fd.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	free(line);
	close(fd);
}