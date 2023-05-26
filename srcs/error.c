/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/26 15:04:18 by zvandeven        ###   ########.fr       */
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
		ft_lstclear(&game->map_lst, &del);
	if (game->map)
		ft_free_ar(game->map);
	if (game->map_path)
		free(game->map_path);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free(game);
	exit (EXIT_FAILURE);
}

void	exit_succes(t_game *game)
{
	if (game->map_lst)
		ft_lstclear(&game->map_lst, &del);
	if (game->map)
		ft_free_ar(game->map);
	if (game->map_path)
		free(game->map_path);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free(game);
	return ;
}
