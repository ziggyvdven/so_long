/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:41:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/08 16:59:32 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_animations(void *param)
{
	t_game			*g;
	static int		i = -1;

	g = param;
	if (i++ == 0)
	{
		mlx_set_instance_depth(&g->enemy->img[0]->instances[0], 300);
		mlx_set_instance_depth(&g->enemy->img[1]->instances[0], 0);
		mlx_set_instance_depth(&g->enemy->img[2]->instances[0], 0);
	}
	if (i == 20)
	{
		mlx_set_instance_depth(&g->enemy->img[0]->instances[0], 0);
		mlx_set_instance_depth(&g->enemy->img[1]->instances[0], 300);
		mlx_set_instance_depth(&g->enemy->img[2]->instances[0], 0);
	}
	if (i == 40)
	{
		mlx_set_instance_depth(&g->enemy->img[0]->instances[0], 0);
		mlx_set_instance_depth(&g->enemy->img[1]->instances[0], 0);
		mlx_set_instance_depth(&g->enemy->img[2]->instances[0], 300);
	}
	if (i == 60)
		i = -1;
}
