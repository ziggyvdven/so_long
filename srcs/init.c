/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:37:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/12 16:15:35 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*game_init(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc((sizeof(t_game)), 1);
	if (!game)
		return (NULL);
	game->argc = argc;
	game->map = ft_strjoin("./maps/", argv[1]);
	game->mlx = NULL;
	game->width = 0;
	game->height = 0;
	game->move_count = 0;
	return (game);
}
