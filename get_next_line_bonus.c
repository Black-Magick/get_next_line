/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:02:50 by remanuel          #+#    #+#             */
/*   Updated: 2023/01/19 13:28:51 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE];
	char		*return_line;
	int			index;

	index = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd > FOPEN_MAX)
	{
		while (fd > 0 && fd < FOPEN_MAX && buffer[index])
			buffer[fd][index++] = 0;
		return (NULL);
	}
	return_line = NULL;
	while (buffer[fd][0] != '\0' || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		return_line = n_strjoin(return_line, buffer[fd]);
		if (n_remover(buffer[fd]) != 0)
			break ;
	}
	return (return_line);
}

/*
int main()
{
	int fd = 0;
	int fd1 = 0;
	int fd2 = 0;
	char *fdline;
	char *fd1line;
	char *fd2line;
	fd = open("./fd.txt", O_RDONLY);
	fd1 = open("./fd1.txt", O_RDONLY);
	fd2 = open("./fd2.txt", O_RDONLY);
	//while (1)
	//{
		//line = get_next_line(fd);
		//if (line == NULL)
		//	break ;
		//printf("%s", get_next_line(fd));
		//printf("FD Line:%s", get_next_line(fd));
		//printf("FD Line:%s", get_next_line(fd));
		//if (get_next_line(fd) == NULL)
		//	break ;
		fdline = get_next_line(fd);
		printf("FD:%s", fdline);
		fd1line = get_next_line(fd1);
		printf("FD1:%s", fd1line);
		fd2line = get_next_line(fd2);
		printf("FD2:%s", fd2line);
	//}
	//printf("\n%d", fd);
	free(fdline);
	free(fd1line);
	free(fd2line);
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}*/