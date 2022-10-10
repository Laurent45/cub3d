/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:01:18 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 15:42:40 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
/* Parse d'un fichier en format .cub avc contenant les textures, les couleurs
	et la map du jeu */
typedef enum e_error
{
	ERR_ARG_NBR,
	ERR_EMPTY_ENV,
	ERR_VALID_NAME,
	ERR_VALID_FILE,
	ERR_MTPL_CHARA,
	ERR_WRONG_CHARA,
	ERR_MALLOC,
	ERR_EMPTY_FILE,
	ERR_NOT_VALID_LINE,
	ERR_MISSING_INFO,
	ERR_MISSING_MAP,
	ERR_MALLOC_2,
	ERR_MAP
}	t_error;

typedef enum e_direction
{
	NO_DIRECTION,
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

typedef enum e_state
{
	WALL,
	INSIDE,
	OUTSIDE,
	FALSE
}	t_state;

/* Structure contenant les textures pour les murs et les couleurs pour sol et
	plafond */
typedef struct s_texture
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_rgb;
	int		ceiling_rgb;
}	t_texture;

/* Structure pour le bonus ou le plafond et le sol ont une texture */

typedef struct s_texture_b
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*fl_texture;
	char	*ce_texture;
}	t_texture_b;

/* La map est un tableu d'int ** donc on conserve width (=largeur) et
	height (=hauteur) pour parcourir le tableau plus facilement 
	direction peut prendre 4 valeurs (1 a 4) correspondant respectivement a 
	N, S, W ,E ou faire un enum ? */
typedef struct s_map
{
	int			**map;
	int			width;
	int			height;
	t_texture	*texture;
	t_direction	direction;
	int			posX;
	int			posY;
}	t_map;

/*Parsing*/
t_map	*parsing(int argc, char **argv, char **envp);
int		check_cub(char **argv);
int		valid_walls(t_map *map);
int		valid_map(int fd, t_map **map);
int		valid_walls(t_map *map);
int		missing_info(t_map **map);
int		open_file(char *cub_file, int *fd);
void	stock_texture(char *line, t_map **map);
int		texture_line(char *line);
int		read_map(int fd, char *line, t_map *map);
int		map_line(char *line, int j);

/*Utils*/
char	*next_line(int fd, char *line);
int		strisint8(char *str);
void	free_split(char **split_tab);
void	free_map(t_map *map, int i);
int		compare(int a, int b);

/*Error management*/

t_map	*p_error(t_error type, char *cub_file, int fd);
int		*p_error_map(t_error type, int *tab);
int		p_error_int(t_error type, t_map *map, int fd, char *line);

#endif