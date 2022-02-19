/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:13:41 by rmerzak           #+#    #+#             */
/*   Updated: 2022/02/17 00:51:36 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"
char	*get_next_line(int fd)
{
	char	save[999999];
	char	*line;
	int		i;
	char	buff[1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = (char *)malloc((i + 1)*sizeof(char));
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return	(line);
}

int main(void)
{
	char *line;
	int fd;
	
	fd = open("text.c",O_RDONLY);
	line  = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		line  = get_next_line(fd);
	}
}	
