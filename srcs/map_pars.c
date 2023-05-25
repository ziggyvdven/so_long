/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:16 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/24 18:21:00 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*map_init(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map_path, O_RDONLY);
	if (fd == -1)
		exit_failure(game, "Error\nFAILED TO OPEN MAP");
	game->map_lst = ft_lstnew(get_next_line(fd));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(game->map_lst, ft_lstnew(line));
	}
	game->width = ft_strlen(game->map_lst->str) - 1;
	game->height = ft_lstsize(game->map_lst);
	if (close(fd) == -1)
		exit_failure(game, "Error\nFAILED TO CLOSE MAP");
	game = make_map(game);
	return (game);
}

t_game	*make_map(t_game *game)
{
	uint32_t	i;
	t_node		*ptr;

	i = 0;
	ptr = game->map_lst;
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		exit_failure(game, "Error\nUNABLE TO MALLOC MAP");
	while (i < game->height)
	{
		game->map[i++] = ft_strdup(ptr->str);
		ptr = ptr->next;
	}
	game->map[i] = NULL;
	return (game);
}

void	map_valid(t_game *game)
{
	if (!(ft_strnstr(game->map_path, ".ber", strlen(game->map_path))))
		exit_failure(game, "Error\nINVALID MAP (not .ber)");
	if (!map_rec(game))
		exit_failure(game, "Error\nINVALID MAP (NOT RECTANGULAR)");
	if (!map_close(game))
		exit_failure(game, "Error\nINVALID MAP (NOT CLOSED)");
	if (map_entries(game, "01CEP"))
		exit_failure(game, map_entries(game, "01CEP"));
	if (map_elements(game))
		exit_failure(game, map_elements(game));
	if (flood_fill(game))
		exit_failure(game, "Error\nINVALID MAP (FLOOD)");
}

t_game	*map_pars(t_game *game)
{
	if (game->argc != 2)
		return (NULL);
	game = map_init(game);
	map_valid(game);
	ft_printlst(game->map_lst);
	return (game);
}
