/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:42:31 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/09 23:50:36 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_ex(char **s)
{
	int	i;

	i = 0;
	while (s[1][i])
		i++;
	if (s[1][i - 1] != 'r' || s[1][i - 2] != 'e'
		|| s[1][i - 3] != 'b' || s[1][i - 4] != '.')
	{
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putstr("Error\nWrong parametres, try <", 2);
		ft_putstr(av[0], 2);
		ft_putstr(" map.ber>", 2);
		return (1);
	}
	if (check_ex(av))
	{
		ft_putstr("Error\nInvalid map extantion '.ber'", 2);
		return (1);
	}
	initialz(&game, av[1]);
	mlx_hook(game.window, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	render_walls(&game);
	mlx_loop(game.mlx);
	return (0);
}
