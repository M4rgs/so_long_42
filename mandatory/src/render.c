/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:06:39 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/07 16:22:46 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_images(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall.img, x * 50, y * 50);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectxpm.img, x * 50, y * 50);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit.img, x * 50, y * 50);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.img, x * 50, y * 50);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->floor.img, x * 50, y * 50);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_images(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	free_map(t_game *game, int flag, char *map_file)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
	}
	if (flag == -1)
		exit(1);
	if (flag == 0)
		map(game, map_file);
}
