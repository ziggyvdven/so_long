/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/01 14:45:04 by zvan-de-         ###   ########.fr       */
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
# include	<fcntl.h>
# define WIDTH 1600
# define HEIGHT 1600
# define TILE 100

typedef struct s_game		t_game;
typedef struct s_images		t_images;
typedef struct s_player		t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	int			argc;
	char		*map_path;
	char		**map;
	int			collectables;
	int			collected;
	t_node		*map_lst;
	t_images	*img;
	uint32_t	width;
	uint32_t	height;
	t_player	*player;
}				t_game;

typedef struct s_map
{
	int			x;
	int			y;
	int			collectables;
	int			exit;
	char		**map;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			move_count;
	mlx_image_t	*char_up;
	mlx_image_t	*char_down;
	mlx_image_t	*char_left;
	mlx_image_t	*char_right;
}				t_player;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall_t;
	mlx_image_t		*wall_b;
	mlx_image_t		*wall_l;
	mlx_image_t		*wall_r;
	mlx_image_t		*wall_e;
	mlx_image_t		*coll;
	mlx_image_t		*exit;
}				t_images;

typedef struct s_data
{
	int		player;
	int		exit;
	int		x;
	int		y;
}				t_data;

/*CHECKS*********************************/
void			map_valid(t_game *game);
int				map_rec(t_game *game);
int				map_close(t_game *game);
char			*map_entries(t_game *game, char *str);
char			*map_elements(t_game *game);
int				flood_fill(t_game *game);

/*PLAYER*******************************/
void			ft_player(t_game *game);
void			ft_moves(mlx_key_data_t keydata, void *param);
void			ft_close(void *param);
int				ft_movable(mlx_key_data_t keydata, t_game *game);
void			ft_move(mlx_key_data_t keydata, t_game *game);
void			check_pos(void *param);

/*INIT**********************************/
t_game			*map_init(t_game *game);
t_game			*game_init(int argc, char **argv);
t_player		*init_player(void);
t_images		*init_images(void);
t_game			*load_png(t_game *game);
t_data			*init_data(void);

/*MAP**********************************/
t_game			*map_pars(t_game *game);
t_game			*make_map(t_game *game);
t_game			*fill_map(t_game *game);
void			fill_backgr(t_game *g, t_images *img, uint32_t x, uint32_t y);
t_game			*fill_elements(t_game *game, t_images *img);

/*ERRORS******************************/
void			exit_failure(t_game *game, char *error_message);
void			putstr_exit(char *str, int fd);
void			exit_succes(t_game *game);
void			game_free(t_game *game);

#endif