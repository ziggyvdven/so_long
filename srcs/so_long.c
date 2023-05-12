/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/11 20:43:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#define WIDTH 1024
#define HEIGHT 1024
#define BPP sizeof(int32_t)


static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	(void)param;
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	mlx_image_t	*img;

	img = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		img->instances[0].y -= 50;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit (0);
	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		img->instances[0].x -= 50;

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		img->instances[0].x += 50;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		img->instances[0].y += 50;
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	
	texture = mlx_load_png("./42_logo.png");
	img = mlx_texture_to_image(mlx, texture);

	if (mlx_image_to_window(mlx, img, 250, 250) < 0)
        error();
	texture = mlx_load_png("./guysouth111.png");
	img = mlx_texture_to_image(mlx, texture);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_key_hook(mlx, &my_keyhook, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

