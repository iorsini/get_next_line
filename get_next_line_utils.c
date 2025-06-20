/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:30:23 by iorsini-          #+#    #+#             */
/*   Updated: 2025/06/20 15:38:42 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*sjoin;
	int		i;
	int		j;

	sjoin = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!sjoin)
		return (free(line), NULL);
	i = 0;
	j = 0;
	while (line != NULL && line[i] != '\0')
	{
		sjoin[i] = line[i];
		i++;
	}
	while (j < BUFFER_SIZE && buffer[j] != '\0' && buffer[j] != '\n')
	{
		sjoin[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		sjoin[i + j] = buffer[j];
	j = j + (buffer[j] == '\n');
	sjoin[i + j] = '\0';
	return (free(line), sjoin);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

int	ft_strchr(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	shift(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[j + i];
		j++;
	}
	buffer[j] = '\0';
}
