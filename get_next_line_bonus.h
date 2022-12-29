/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:34:41 by mbouderr          #+#    #+#             */
/*   Updated: 2022/12/28 06:34:43 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif

#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void *ft_calloc(size_t count, size_t size);
char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(char *str);
ssize_t ft_strchr(char *s, int c);
char *ft_substr(char *s, unsigned int start, size_t len);
char *Cleaner(char *dirtline);
void ft_bzero(void *s, size_t n);
char *Linereader(int fd, int *readcounter, char *buffereader);

#endif