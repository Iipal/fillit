/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:33 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/08 21:37:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		**get_chunkf(t_file *file, t_figurelist *figure_list,
									int i)
{
	char	**cut_fig;
	int		j;
	int		k;
	
	figure_list->curr_fig->width = figure_list->curr_fig->max.x -
		figure_list->curr_fig->min.x + 1;
	figure_list->curr_fig->height = figure_list->curr_fig->max.y -
		figure_list->curr_fig->min.y + 1;
	_ERR_NOTIS_O(cut_fig = (char **)malloc(sizeof(char *) *
		(figure_list->curr_fig->height + 1)), NULL);
	k = 0;
	j = -1;
	while (++j < figure_list->curr_fig->height)
	{
		_ERR_NOTIS_O(cut_fig[j] = ft_strnew(figure_list->curr_fig->width),
											NULL);
		cut_fig[j] = ft_strncpy(cut_fig[j], &file->tab
			[i + figure_list->curr_fig->min.y + k]
			[figure_list->curr_fig->min.x], figure_list->curr_fig->width);
		++k;
	}
	return (cut_fig);
}

static void		find_range_add(t_figurelist *figure_list, int i, int j)
{
	figure_list->curr_fig->min.y = (i % 5 < figure_list->curr_fig->min.y)
		? i % 5 : figure_list->curr_fig->min.y;
	figure_list->curr_fig->max.y = (i % 5 > figure_list->curr_fig->max.y)
		? i % 5 : figure_list->curr_fig->max.y;
	figure_list->curr_fig->min.x = (j < figure_list->curr_fig->min.x)
		? j : figure_list->curr_fig->min.x;
	figure_list->curr_fig->max.x = (j > figure_list->curr_fig->max.x)
		? j : figure_list->curr_fig->max.x;
}

static void		find_range(t_figurelist *figure_list,
							t_file *file, int i)
{
	int		i_1;
	int		j;

	i_1 = i + 4;
	figure_list->curr_fig->min.x = 3;
	figure_list->curr_fig->min.y = 3;
	figure_list->curr_fig->max.y = 0;
	figure_list->curr_fig->max.x = 0;
	while (i < i_1)
	{
		j = -1;
		while (++j < 4)
			if (file->tab[i][j] == '#')
				find_range_add(figure_list, i, j);
		++i;
	}
}

t_figurelist	*ft_cut_figure(t_file *file)
{
	int				i;
	t_figurelist	*flist;
	t_figurelist	*temp;
	int				j;

	i = 0;
	_ERR_NOTIS_O(flist = (t_figurelist *)malloc(sizeof(t_figurelist)), NULL);
	while ((unsigned int)i < file->lines)
	{
		j = -1;
		_ERR_NOTIS_O(flist->curr_fig = (t_figure*)malloc(
											sizeof(t_figure)), NULL);
		temp = (i == 0) ? flist : temp;
		find_range(flist, file, i);
		_ERR_NOTIS_O(flist->curr_fig->tab = get_chunkf(file, flist, i), NULL);
		i += 5;
		if (i > (int)file->lines)
			flist->next = NULL;
		else
			_ERR_NOTIS_O(flist->next = (t_figurelist*)malloc(
											sizeof(t_figurelist)), NULL);
		flist = flist->next;
	}
	flist = temp;
	return (flist);
}
