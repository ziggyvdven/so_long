/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/08 16:08:29 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_close(void *param)
{
	t_game	*game;

	game = param;
	exit_succes(game);
}

int32_t	main(int argc, char **argv)
{
	t_game			*game;

	game = game_init(argc, argv);
	map_pars(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * 96, game->height * 96, "so_long", true);
	if (!game->mlx)
		exit_failure(game, "Error\nUNABLE TO INITIALIZE MLX");
	game = fill_map(game);
	ft_player(game, game->player);
	ft_enemy(game);
	mlx_loop_hook(game->mlx, &ft_animations, game);
	mlx_close_hook(game->mlx, &ft_close, game);
	mlx_loop(game->mlx);
	return (0);
}
