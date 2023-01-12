/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:36:21 by mbouderr          #+#    #+#             */
/*   Updated: 2023/01/12 16:49:53 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			readcounter;
	char		*buffereader;
	static char	*frag[OPEN_MAX];

	buffereader = ft_calloc(BUFFER_SIZE + 2, 1);
	readcounter = 1;
	if (frag[fd])
	{
		buffereader = ft_strjoin(buffereader, frag[fd]);
		free(frag[fd]);
		frag[fd] = NULL;
	}
	buffereader = linereader(fd, &readcounter, buffereader);
	if (buffereader && ft_strchr(buffereader, '\n') != -1)
	{
		frag[fd] = ft_substr(buffereader, ft_strchr(buffereader, '\n') + 1,
				ft_strchr(buffereader, '\0'));
		buffereader = cleaner(buffereader);
	}
	if (readcounter == 0 && ft_strlen(buffereader) == 0)
	{
		free(buffereader);
		return (NULL);
	}
	return (buffereader);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)s;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}

char	*linereader(int fd, int *readcounter, char *buffereader)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while ((ft_strchr(buffer, '\n') == -1) && (*readcounter > 0))
	{
		ft_bzero(buffer, BUFFER_SIZE);
		*readcounter = read(fd, buffer, BUFFER_SIZE);
		if (*readcounter == -1)
		{
			free(buffereader);
			free(buffer);
			return (NULL);
		}
		buffereader = ft_strjoin(buffereader, buffer);
	}
	free(buffer);
	return (buffereader);
}

char	*cleaner(char *dirtline)
{
	char	*cleanline;

	cleanline = ft_substr(dirtline, 0, ft_strchr(dirtline, '\n') + 1);
	free(dirtline);
	return (cleanline);
}
// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     int fd2 = open("test2.txt", O_RDONLY);
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd2));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd2));

// }