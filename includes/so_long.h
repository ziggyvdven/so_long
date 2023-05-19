/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/19 17:42:34 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../libs/libft/includes/libft.h"
# include	"../libs/MLX42/include/MLX42/MLX42.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<stdbool.h>
# include	<limits.h>
# include 	<fcntl.h>
# define 	WIDTH 1500
# define 	HEIGHT 1500

typedef struct s_game	t_game;

typedef struct s_game
{
	mlx_t		*mlx;
	int			argc;
	char		*map_path;
	char		**map;
	int			collectables;
	t_node		*map_lst;
	uint32_t	move_count;
	uint32_t	width;
	uint32_t	height;
}				t_game;


/*CHECKS*********************************/
void			map_valid(t_game *game);
int				map_rec(t_game *game);
int				map_close(t_game *game);
char			*map_entries(t_game *game, char *str);
char			*map_elements(t_game *game);

/*KEYHOOKS*******************************/
void			ft_keyhooks(mlx_t *mlx, void *param);
void			ft_keyhook(mlx_key_data_t keydata, void *param);
void			ft_scrollhook(double xdelta, double ydelta, void *param);

/*INIT**********************************/
t_game			*map_init(t_game *game);
t_game			*map_pars(t_game *game);
t_game			*game_init(int argc, char **argv);
t_game			*make_map(t_game *game);

/*ERRORS******************************/
void			exit_failure(t_game *game, char *error_message);
void			putstr_exit(char *str, int fd);
void			exit_succes(t_game *game);

#endif