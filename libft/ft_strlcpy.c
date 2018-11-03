/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:15:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t dstsize)
{
	size_t	strsize;

	if (str == NULL)
		return (0);
	strsize = ft_strlen(str);
	if (strsize < dstsize)
		ft_memcpy(dest, str, strsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dest, str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
