/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/19 17:48:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	putstr_exit(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(0);
}

int32_t	main(int argc, char **argv)
{
	t_game			*game;
	mlx_image_t		*img = NULL;
	mlx_texture_t	*texture = NULL;

	game = game_init(argc, argv);
	map_pars(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * 75, game->height * 75, "so_long", true);
	if (!game->mlx)
		exit_failure(game, "Error\nUNABLE TO INITIALIZE MLX");
	texture = mlx_load_png("./textures/char.png");
	img = mlx_texture_to_image(game->mlx, texture);
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
		error();
	ft_keyhooks(game->mlx, img);
	mlx_loop(game->mlx);
	free (img);
	img = NULL;
	free (texture);
	texture = NULL;
	exit_succes(game);
	return (0);
}

