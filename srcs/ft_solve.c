/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:38:49 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/09 12:38:50 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	ft_alloc_on_map(t_map *map, t_figurelist *fl,
									t_point point, char ch)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fl->curr_fig->width)
	{
		j = -1;
		while (++j < fl->curr_fig->height)
			if (fl->curr_fig->tab[j][i] == '#')
				map->tab[point.y + j][point.x + i] = ch;
	}
}

static bool	ft_empty_place(t_map *map, t_figurelist *fl, t_point point)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fl->curr_fig->width)
	{
		j = -1;
		while (++j < fl->curr_fig->height)
			if (fl->curr_fig->tab[j][i] == '#' &&
				map->tab[point.y + j][point.x + i] != '.')
				return (false);
	}
	ft_alloc_on_map(map, fl, point, fl->curr_fig->symb);
	return (true);
}

bool		ft_btsmap(t_map *map, t_figurelist *fl)
{
	t_point		point;

	if (!fl)
		return (true);
	point.y = -1;
	while (++(point.y) < map->size - fl->curr_fig->height + 1)
	{
		point.x = -1;
		while (++(point.x) < map->size - fl->curr_fig->width + 1)
		{
			if (ft_empty_place(map, fl, point))
			{
				if (ft_btsmap(map, fl->next))
					return (true);
				else
					ft_alloc_on_map(map, fl, point, '.');
			}
		}
	}
	return (false);
}

bool		ft_solve(t_figurelist *fl)
{
	t_map	*map;
	int		map_size;
	int		i;

	_ERR_NOTIS(map = ft_create_map(ft_mapsize(fl)));
	while (ft_btsmap(map, fl) == false)
	{
		i = -1;
		ft_free_map(&map);
		map_size = ++(map->size);
		free(map);
		_ERR_NOTIS(map = ft_create_map(map_size));
	}
	ft_display_map(map);
	ft_free_map(&map);
	free(map);
	return (true);
}
