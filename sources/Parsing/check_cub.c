/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:20:23 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/21 12:00:48 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	check_cub(char **argv)
{
	int	size;

	size = ft_strlen(argv[1]);
	if (size <= 4)
		return (1);
	else
	{
		if (ft_strncmp(&(argv[1][size - 4]), ".cub", 5))
			return (1);
	}
	return (0);
}

/* TEST REALISES */
/* Valide : */
// map.cub
// map..cub
// map.cub.cub

/* Invalide : */
// mapcub
// .cub
// smap.cu