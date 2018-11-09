/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:39:06 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/09 12:39:07 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_display_map(t_map *map)
{
	int		i;

	i = -1;
	while (map->tab[++i] && i < map->size)
		ft_putendl(map->tab[i]);
}

int			ft_mapsize(t_figurelist *flist)
{
	int	list_size;
	int	out_size;

	list_size = 0;
	out_size = 2;
	while (flist)
	{
		list_size++;
		flist = flist->next;
	}
	while (out_size * out_size < list_size * 4)
		out_size++;
	return (out_size);
}

t_map		*ft_create_map(int size)
{
	t_map	*new;
	int		i;

	i = -1;
	new = (t_map *)malloc(sizeof(t_map));
	new->size = size;
	new->tab = (string *)malloc(sizeof(string) * size);
	while (++i < size)
	{
		new->tab[i] = ft_strnew(size);
		new->tab[i] = (string)ft_memset((void *)(new->tab[i]), '.', size);
	}
	return (new);
}

void		ft_free_map(t_map **map)
{
	int				i;

	i = -1;
	while (++i < (*map)->size)
		free((*map)->tab[i]);
	free((*map)->tab);
}
