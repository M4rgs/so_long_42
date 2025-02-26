/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 07:42:19 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/25 23:13:20 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define CLOSE_KEY 65307

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	char	**map;
	t_img	wall;
	t_img	collectxpm;
	t_img	exit;
	t_img	player;
	t_img	floor;
	int		player_x;
	int		player_y;
	int		collectables;
	int		moves;
}	t_game;

void	ft_putstr(char *s, int f);
void	initialz(t_game *game, char *map_file);
size_t	ft_strlen(char *s);
void	map(t_game *game, char *map_file);
void	check_map(t_game *game, char *map_file);
void	free_map(t_game *game, int flag, char *map_file);
int		close_game(t_game *game);
int		handle_input(int key, t_game *game);
void	free_resources(t_game *game);
int		render_map(t_game *game);
void	ft_putnbr(int nb);
void	print_moves(t_game *game, int moves);
void	ft_putchar(char c);
char	*get_next_line(int fd);
#endif  