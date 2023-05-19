/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/19 17:47:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	del(void *content)
{
	free(content);
}

void	exit_failure(t_game *game, char *error_message)
{
	int	y;

	y = 0;
	ft_putendl_fd(error_message, 2);
	if (game->map_lst)
		ft_lstclear(&game->map_lst, &del);
	if (game->map)
	{
		while (game->map[y] != NULL)
			free(game->map[y++]);
		free(game->map);
	}
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
	int	y;

	y = 0;
	if (game->map_lst)
		ft_lstclear(&game->map_lst, &del);
	if (game->map)
	{
		while (game->map[y] != NULL)
			free(game->map[y++]);
		free(game->map);
	}
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
