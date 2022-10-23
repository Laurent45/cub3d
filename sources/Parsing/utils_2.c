/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:40:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/10/14 12:07:04 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	compare(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	**free_line(char *line, int **tab, int i, int height)
{
	free(line);
	if (i > 0)
	{
		free_tab(tab, i, height);
		return (NULL);
	}
	return (tab);
}

void	free_tab(int **tab, int i, int height)
{
	if (tab)
	{
		while (i < height)
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
