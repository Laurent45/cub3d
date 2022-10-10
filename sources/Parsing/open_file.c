/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:53:16 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/21 14:45:45 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	open_file(char *cub_file, int *fd)
{
	*fd = open(cub_file, O_RDONLY);
	if (*fd == -1)
		return (1);
	return (0);
}

/* TEST REALISES */
//fichier exitant
//fichier inexistant