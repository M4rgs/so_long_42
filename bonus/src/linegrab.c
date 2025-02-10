/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linegrab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:18:46 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/10 03:03:44 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static char	*ft_strdup(char *string)
{
	int		i;
	int		size;
	char	*p;

	i = 0;
	size = ft_strlen(string);
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (0);
	while (string[i])
	{
		p[i] = string[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*line_grabber(int fd)
{
	char	c;
	char	tmp[7000000];
	int		readed;
	int		i;
	char	*line;

	if (fd < 0)
		return (NULL);
	i = 0;
	readed = read(fd, &c, 1);
	while (readed > 0)
	{
		tmp[i++] = c;
		if (c == '\n')
			break ;
		readed = read(fd, &c, 1);
	}
	tmp[i] = '\0';
	if (readed <= 0 && i == 0)
		return (NULL);
	line = ft_strdup(tmp);
	return (line);
}
