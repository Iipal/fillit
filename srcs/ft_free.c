/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:23:12 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/08 10:23:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

bool	ft_free(t_figure **figure)
{
	size_t	i;

	i = -1;
	while (++i < (*figure)->lines)
		free((*figure)->tab[i]);
	free((*figure)->cut->x);
	free((*figure)->cut->y);
	free((*figure)->cut);
	free(*figure);
	*figure = NULL;
	return (true);
}