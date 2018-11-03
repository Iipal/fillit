/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:06:41 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:10:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;

	out = NULL;
	if ((out = (char*)ft_memalloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ft_memset(out, '\0', size + 1);
	return (out);
}
