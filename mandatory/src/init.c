/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/09 21:47:26 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *s, int f)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (f, &s[i], 1);
		i++;
	}
}

static void	shapes(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->collectxpm.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm",
			&game->collectxpm.width, &game->collectxpm.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player.width, &game->player.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	if (!game->wall.img || !game->collectxpm.img || !game->floor.img
		|| !game->player.img || !game->exit.img)
	{
		ft_putstr("Error\nFailed loading textures !\n", 2);
		free_resources(game);
		exit(1);
	}
}

static void	init_game_help(t_game *game)
{
	int	x;
	int	y;

	shapes(game);
	game->collectables = 0;
	game->moves = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->collectables++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	initialz(t_game *game, char *map_file)
{
	map(game, map_file);
	check_map(game, map_file);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr("Error\nMlx initialize faild !\n", 2);
		free_map(game, -1, map_file);
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, game->width * 50,
			game->height * 50, "so long");
	if (!game->window)
	{
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		ft_putstr("Error\nFailed loading window !\n", 2);
		free_map(game, -1, map_file);
	}
	init_game_help(game);
}

int	close_game(t_game *game)
{
	if (game)
		free_resources(game);
	exit(0);
	return (0);
}
