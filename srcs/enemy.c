/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:58:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/08 16:57:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy	*init_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)ft_calloc((sizeof(t_enemy)), 1);
	if (!enemy)
		return (NULL);
	enemy->x = 0;
	enemy->y = 0;
	enemy->img[0] = make_image(game, "./textures/cori1.png");
	enemy->img[1] = make_image(game, "./textures/cori2.png");
	enemy->img[2] = make_image(game, "./textures/cori3.png");
	enemy->img[3] = NULL;
	return (enemy);
}

uint32_t	random_num(void)
{
	uint32_t	r;

	r = 0;
	while (r == 0)
	{
		r = (mlx_get_time() * 10000);
		r %= 10;
	}
	return (r);
}

void	find_random_empty_spot(t_game *g, int x, int y)
{
	while (g->map[y][x] == '1')
	{
		x = random_num() % g->width;
		usleep(10);
		y = random_num() % g->height;
	}
	g->enemy->x = x;
	g->enemy->y = y;
	printf("%d\n", x);
	printf("%d\n", y);
}

void	ft_enemy(t_game *game)
{
	int		i;

	i = 0;
	game->enemy = init_enemy(game);
	find_random_empty_spot(game, 0, 0);
	while (game->enemy->img[i])
		mlx_image_to_window(game->mlx, game->enemy->img[i++],
			game->enemy->x * 96, game->enemy->y * 96);

}
