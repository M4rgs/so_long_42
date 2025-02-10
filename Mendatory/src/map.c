/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:12:51 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/10 06:22:46 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	check_size(int w, int h, char *line, int fd)
{
	if (w > 75 || h > 50)
	{
		while (line)
		{
			free(line);
			line = line_grabber(fd);
		}
		ft_putstr("Error\nMap too big !", 2);
		exit(1);
	}
}

static void	check_widht(int *w, int *h, char *line, int fd)
{
	static int	tmp;

	*w = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		*w -= 1;
	if (tmp && *w != tmp)
	{
		ft_putstr("Invalid Map\nMap size !\n", 2);
		while (line)
		{
			free(line);
			line = line_grabber(fd);
		}
		close(fd);
		exit(1);
	}
	tmp = *w;
	check_size(*w, *h, line, fd);
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
	while (i < height)
	{
		game->map[i] = line_grabber(fd);
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

	height = 0;
	width = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\ncannot read the map file !\n", 2);
		exit (1);
	}
	line = line_grabber(fd);
	while (line)
	{
		check_widht(&width, &height, line, fd);
		height++;
		free(line);
		line = line_grabber(fd);
	}
	close(fd);
	map_helper(game, map_file, height, width);
}
