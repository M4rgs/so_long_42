/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:31:46 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/08 00:00:03 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	change_coll2(t_game *game)
{
	static int	last_time;
	int			current_time;

	current_time = time(NULL);
	if (current_time - last_time >= 2)
	{
		mlx_destroy_image(game->mlx, game->anicollect.img);
		game->anicollect.img = mlx_xpm_file_to_image(game->mlx,
				"textures/collect.xpm", &game->anicollect.width,
				&game->anicollect.height);
		last_time = current_time;
	}
}

void	change_coll(t_game *game)
{
	static int	last_time;
	int			current_time;

	current_time = time(NULL);
	if (current_time - last_time >= 1)
	{
		mlx_destroy_image(game->mlx, game->anicollect.img);
		game->anicollect.img = mlx_xpm_file_to_image(game->mlx,
				"textures/collectmo.xpm",
				&game->anicollect.width, &game->anicollect.height);
		if (!game->anicollect.img)
		{
			ft_putstr("Error\nFailed loading textures !\n", 2);
			free_resources(game);
			exit(1);
		}
		last_time = current_time;
	}
}
