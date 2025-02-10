/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:06:39 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/09 22:15:23 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'N')
		{
			ft_putstr("You Died\n", 1);
			close_game(game);
		}
		if (game->map[new_y][new_x] == 'E' && game->collectables != 0)
			return ;
		if (game->map[new_y][new_x] == 'C')
			game->collectables--;
		if (game->map[new_y][new_x] == 'E' && game->collectables == 0)
		{
			ft_putstr("YOU WIN !!\n", 1);
			close_game(game);
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		print_moves(game, game->moves);
	}
}

int	handle_input(int key, t_game *game)
{
	if (key == CLOSE_KEY)
	{
		ft_putstr("You close the game, BYE BYE :(\n", 1);
		close_game(game);
	}
	else if ((key == 'w' || key == UP) && game->player_y > 0)
		move_player(game, game->player_x, game->player_y - 1);
	else if ((key == 's' || key == DOWN) && game->player_y < game->height - 1)
		move_player(game, game->player_x, game->player_y + 1);
	else if ((key == 'a' || key == LEFT) && game->player_x > 0)
		move_player(game, game->player_x - 1, game->player_y);
	else if ((key == 'd' || key == RIGHT) && game->player_x < game->width - 1)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

static void	free_textures(t_game *game)
{
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->enemy.img)
		mlx_destroy_image(game->mlx, game->enemy.img);
	if (game->left_wall.img)
		mlx_destroy_image(game->mlx, game->left_wall.img);
	if (game->right_wall.img)
		mlx_destroy_image(game->mlx, game->right_wall.img);
	if (game->anicollect.img)
		mlx_destroy_image(game->mlx, game->anicollect.img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_resources(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
	}
	free_textures(game);
}
