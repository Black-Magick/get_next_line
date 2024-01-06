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
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buffer[index] != '\0')
			buffer[index++] = 0;
		return (NULL);
	}
	return_line = NULL;
	while (buffer[0] != '\0' || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		return_line = n_strjoin(return_line, buffer);
		if (n_remover(buffer) != 0)
			break ;
	}
	buffer[BUFFER_SIZE] = '\0';
	return (return_line);
}

/*
//printf("Buffer:%s", buffer); Check it
//printf("\nReturn Line:%s ", return_line); Check it
int main()
{
	int fd = 0;
	char *line;
	fd = open("./fd.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("GNL:%s", line);
	free(line);
	close(fd);
	return (0);
}*/