/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:36:50 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 14:45:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_map	*parsing(int argc, char **argv, char **envp)
{
	t_map	*map;
	int		fd;

	fd = -1;
	map = NULL;
	if (argc != 2)
		return (p_error(ERR_ARG_NBR, NULL));
	if (!envp)
		return (p_error(ERR_EMPTY_ENV, NULL));
	if (check_cub(argv))
		return (p_error(ERR_VALID_NAME, argv[1]));
	if (open_file(argv[1], &fd))
		return (p_error(ERR_VALID_FILE, argv[1]));
	if (valid_map(fd, &map))
		return (NULL);
	if (missing_info(&map))
	{
		free_map(map, 0);
		return (p_error(ERR_MISSING_INFO, NULL));
	}
	return (map);
}
