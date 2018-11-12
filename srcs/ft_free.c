/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:23:14 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/12 11:23:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_free_map(t_map **map)
{
	int				i;

	i = -1;
	while (++i < (*map)->size)
		free((*map)->tab[i]);
	free((*map)->tab);
}

void	ft_free_list(t_figurelist **fl)
{
	t_figurelist	*temp;
	int				i;

	while (*fl)
	{
		temp = (*fl)->next;
		i = -1;
		while (++i < (*fl)->curr_fig->height)
			free((*fl)->curr_fig->tab[i]);
		free((*fl)->curr_fig->tab);
		free((*fl)->curr_fig);
		free(*fl);
		*fl = temp;
	}
}

void	ft_free_file(t_file **file)
{
	int	i;

	i = -1;
	while (++i < ((*file)->lines))
		ft_strdel(&((*file)->tab[i]));
	free((*file)->tab);
	free(*file);
	file = NULL;
}
