/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:09:44 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/27 04:17:21 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	moveemyhelp(int *enemy_x, int *enemy_y, int *new_x, int *new_y)
{
	int	random_dir;
	int	directions[4][2];

	srand(time(NULL));
	directions[0][0] = 0;
	directions[0][1] = -1;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 1;
	directions[3][1] = 0;
	random_dir = rand() % 4;
	*new_x = *enemy_x + directions[random_dir][0];
	*new_y = *enemy_y + directions[random_dir][1];
}

static void	moveenemy(t_game *game, int enemy_x, int enemy_y)
{
	int	k;
	int	new_x;
	int	new_y;

	k = 0;
	while (k == 0)
	{
		moveemyhelp(&enemy_x, &enemy_y, &new_x, &new_y);
		if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'P')
		{
			k = 1;
		}
		if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'C'
			|| game->map[new_y][new_x] == 'N')
			return ;
		if (game->map[new_y][new_x] == 'P')
		{
			ft_putstr("You Died LOL\n", 1);
			close_game(game);
		}
	}
	game->map[enemy_y][enemy_x] = '0';
	enemy_x = new_x;
	enemy_y = new_y;
	game->map[enemy_y][enemy_x] = 'N';
}

static int	find_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'N')
				moveenemy(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	move_enemy_with_delay(t_game *game)
{
	static int	last_time;
	int			current_time;

	current_time = time(NULL);
	if (current_time - last_time >= 1)
	{
		find_enemy(game);
		last_time = current_time;
	}
	return (0);
}
