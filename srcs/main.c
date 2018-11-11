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

bool	ft_errno_args(int *argc)
{
	(*argc)--;
	if (!*argc || *argc > 1)
		return (false);
	return (true);
}

int		main(int argc, string *argv)
{
	t_file			*file;
	t_figurelist	*figure_list;

	argv++;
	_ERR_NOTIS_MSG(file = (t_file*)malloc(sizeof(t_file)));
	if (ft_errno_args(&argc) && *argv)
	{
		_ERR_NOTIS_MSG(ft_read_file(*argv, &file));
		_ERR_NOTIS_MSG(ft_valid_file(file));
		_ERR_NOTIS_MSG(figure_list = ft_cut_figure(file));
		ft_free_file(&file);
		_ERR_NOTIS_MSG(ft_solve(figure_list));
		ft_free_list(&figure_list);
	}
	else
		_ERR_MSG("usage: ./fillit <file_name>");
}
