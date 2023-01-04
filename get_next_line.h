/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:34:15 by remanuel          #+#    #+#             */
/*   Updated: 2023/01/04 15:14:21 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <fcntl.h> //This is the lib that contains fopen
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 50
#endif

size_t	n_strlen(char *str);
char	*n_strjoin(char *read_line, char *buffer);
int		n_remover(char *buffer);
char	*get_next_line(int fd);

#endif