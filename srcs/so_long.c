/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/21 17:07:43 by zvan-de-         ###   ########.fr       */
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
	game->mlx = mlx_init(game->width * 75, game->height * 75, "so_long", true);
	if (!game->mlx)
		exit_failure(game, "Error\nUNABLE TO INITIALIZE MLX");
	game = fill_map(game);
	ft_player(game);
	mlx_close_hook(game->mlx, &ft_close, game);
	mlx_loop(game->mlx);
	exit_succes(game);
	return (0);
}
