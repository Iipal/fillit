/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:07:54 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/08 21:37:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_free_file(t_file **file);
void	ft_free_list(t_figurelist **fl);
bool	ft_errno_args(int *argc);

int		main(int argc, string *argv)
{
	t_file			*file;
	t_figurelist	*figure_list;

	argv++;
	_ERR_NOTIS_MSG(file = (t_file*)malloc(sizeof(t_file)),
						"failure with struct allocation.");
	if (ft_errno_args(&argc) && *argv)
	{
		_ERR_NOTIS_MSG(ft_read_file(*argv, &file),
						"failure with file reading.");
		_ERR_NOTIS_MSG(ft_valid_file(file),
						"failure file validating.");
		_ERR_NOTIS_MSG(figure_list = ft_cut_figure(file),
						"failure figure cuting.");
		ft_free_file(&file);
		ft_free_list(&figure_list);
	}
	else
		_ERR_MSG("where is file name ?");
}

bool	ft_errno_args(int *argc)
{
	(*argc)--;
	if (!*argc || *argc > 1)
		return (false);
	return (true);
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
	int				i;

	i = -1;
	while ((size_t)++i < (*file)->lines)
		free((*file)->tab[i]);
	free((*file)->tab);
	free(*file);
	file = NULL;
}