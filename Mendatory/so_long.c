/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:42:31 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/07 14:04:39 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error\nWrong parametres, try <", 2);
		ft_putstr(av[0], 2);
		ft_putstr(" map.ber>", 2);
		return (1);
	}
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e'
		|| av[1][i - 3] != 'b' || av[1][i - 4] != '.')
	{
		ft_putstr("Error\nInvalid map extantion '.ber'", 2);
		return (1);
	}
	initialz(&game, av[1]);
	mlx_hook(game.window, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
