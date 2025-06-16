/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:28:32 by iorsini-          #+#    #+#             */
/*   Updated: 2025/06/16 16:23:17 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || buffer[0] == 0)
			return (free(line), shift(buffer), NULL);
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (shift(buffer), line);
}
/*
int	main(void)
{
	int		fd;
	char	*linha;
	int		contador = 1;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	while ((linha = get_next_line(fd)) != NULL)
	{
		printf("Chamada %d: %s", contador, linha);
		free(linha);
		contador++;
	}
	close(fd);
	return (0);
}*/
