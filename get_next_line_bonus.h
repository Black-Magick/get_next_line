#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

size_t	n_strlen(char *str);
char	*n_strjoin(char *read_line, char *buffer);
int		n_remover(char *buffer);
char	*get_next_line(int fd);

#endif