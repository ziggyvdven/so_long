/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/12 14:42:58 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	(void)param;
	(void)xdelta;
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_image_t	*img;

	img = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		img->instances[0].y -= 75;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit (0);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		img->instances[0].x -= 75;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		img->instances[0].x += 75;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		img->instances[0].y += 75;
}

void	ft_keyhooks(mlx_t *mlx, void *param)
{
	mlx_image_t		*img;

	img = param;
	mlx_scroll_hook(mlx, &ft_scrollhook, NULL);
	mlx_key_hook(mlx, &ft_keyhook, img);
}
