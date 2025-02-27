/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:03:26 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/27 03:30:34 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_chara(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->width)
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < game->height)
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != '0' \
			&& game->map[i][j] != 'P'\
			&& game->map[i][j] != 'E' && game->map[i][j] != '1'
			&& game->map[i][j] != 'N')
				return (0);
		}
	}
	return (1);
}

static int	check_require(t_game *game)
{
	int	i;
	int	j;
	int	flag[3];

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				flag[0]++;
			else if (game->map[i][j] == 'E')
				flag[1]++;
			else if (game->map[i][j] == 'C')
				flag[2]++;
		}
	}
	if (flag[0] != 1 || flag[1] != 1 || !flag[2])
		return (0);
	return (1);
}

static int	valid_map_path(t_game *game, int w, int h, char c)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if ((game->map[h][w] == '1') || (game->map[h][w] == 'N')
		|| (game->map[h][w] == 'E' && c == 'P'))
		return (0);
	if (game->map[h][w] == c)
		return (1);
	game->map[h][w] = '1';
	up = valid_map_path(game, w, h - 1, c);
	down = valid_map_path(game, w, h + 1, c);
	right = valid_map_path(game, w + 1, h, c);
	left = valid_map_path(game, w - 1, h, c);
	return (up || down || right || left);
}

static int	check_valid_map(t_game *game, char *map_file)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (!valid_map_path(game, x, y, 'E'))
					return (0);
				free_map(game, 0, map_file);
			}
			if (game->map[y][x] == 'C')
			{
				if (!valid_map_path(game, x, y, 'P'))
					return (0);
				free_map(game, 0, map_file);
			}
		}
	}
	return (1);
}

void	check_map(t_game *game, char *map_file)
{
	if (!check_chara(game))
	{
		ft_putstr("Error\nInvalid components !\n", 2);
		free_map(game, -1, map_file);
	}
	if (!check_require(game))
	{
		ft_putstr("Error\nComponents must be one player,\
			One exit, Atleat one collectable !\n", 2);
		free_map(game, -1, map_file);
	}
	if (!check_valid_map(game, map_file))
	{
		ft_putstr("Error\nNo valid path !\n", 2);
		free_map(game, -1, map_file);
	}
}
