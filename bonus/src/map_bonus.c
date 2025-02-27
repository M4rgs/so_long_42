/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:12:51 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/28 03:20:36 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	check_mapsize(int *w, int *h, char *line, int fd)
{
	static int	tmp;

	*w = ft_strlen(line);
	if (ft_strchr(line, '\n') && line[0] != '\n')
		*w -= 1;
	if ((tmp && *w != tmp) || (*h > 55 || *w > 79))
	{
		ft_putstr("Invalid Map\nMap size !\n", 2);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		exit(1);
	}
	tmp = *w;
}

static void	map_helper(t_game *game, char *map_file, int height, int width)
{
	int	fd;
	int	i;

	i = 0;
	game->width = width;
	game->height = height;
	game->map = (char **)malloc(sizeof(char *) * height);
	if (!game->map)
	{
		ft_putstr("Error\nNo memory for map !\n", 2);
		exit(1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		exit(1);
	}
	while (i < height)
	{
		game->map[i] = get_next_line(fd);
		game->map[i][width] = '\0';
		i++;
	}
	close (fd);
}

void	map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	int		temp;

	height = 0;
	width = 0;
	temp = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\ncannot read the map file !\n", 2);
		exit (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		check_mapsize(&width, &height, line, fd);
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map_helper(game, map_file, height, width);
}
