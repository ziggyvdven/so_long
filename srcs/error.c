/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/31 19:15:32 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	del(void *content)
{
	free(content);
}

void	exit_failure(t_game *game, char *error_message)
{
	ft_putendl_fd(error_message, 2);
	if (game->map_lst)
	{
		ft_lstclear(&game->map_lst, &del);
		free(game->map_lst);
	}
	if (game->map)
		ft_free_ar(game->map);
	if (game->map_path)
		free(game->map_path);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	game_free(game);
	exit (EXIT_FAILURE);
}

void	exit_succes(t_game *game)
{
	if (game->map_lst)
	{
		ft_lstclear(&game->map_lst, &del);
		free(game->map_lst);
	}
	if (game->map)
		ft_free_ar(game->map);
	if (game->map_path)
		free(game->map_path);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	game_free(game);
	exit (EXIT_SUCCESS);
}
