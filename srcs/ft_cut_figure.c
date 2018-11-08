/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_figu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:33 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/07 16:33:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			**get_chunk_figure(t_file *file, t_figurelist *figure_list,
									int i)
{
	char	**cut_fig;
	int		j;
	int		k;

	k = 0;
	j = -1;
	// printf("sdklfdlkfg\n");
	figure_list->curr_fig->width = figure_list->curr_fig->max.x -
		figure_list->curr_fig->min.x + 1;
	figure_list->curr_fig->height = figure_list->curr_fig->max.y -
		figure_list->curr_fig->min.y + 1;
	cut_fig = (char **)malloc(sizeof(char *) *
		(figure_list->curr_fig->height + 1));
	while (++j < figure_list->curr_fig->height)
	{
		cut_fig[j] = ft_strnew(figure_list->curr_fig->width);
		cut_fig[j] = ft_strncpy(cut_fig[j], &file->tab
			[i + figure_list->curr_fig->min.y + k]
			[figure_list->curr_fig->min.x], figure_list->curr_fig->width);
		++k;
	}
	return (cut_fig);
}

void			find_range_add(t_figurelist *figure_list, int i, int j)
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

void			find_range(t_figurelist *figure_list,
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
	t_figurelist	*figure_list;
	t_figurelist	*temp;
	int				j;

	i = 0;
	figure_list = (t_figurelist *)malloc(sizeof(t_figurelist));
	while ((unsigned int)i < file->lines)
	{
		j = -1;
		figure_list->curr_fig = (t_figure *)malloc(sizeof(t_figure));
		temp = (i == 0) ? figure_list : temp;
		find_range(figure_list, file, i);
		figure_list->curr_fig->tab = get_chunk_figure(file, figure_list, i);
		i += 5;
		if (i > (int)file->lines)
			figure_list->next = NULL;
		else
			figure_list->next = (t_figurelist *)malloc(sizeof(t_figurelist));
		figure_list = figure_list->next;
	}
	figure_list = temp;
	return (figure_list);
}
