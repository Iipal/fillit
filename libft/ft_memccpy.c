/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:04:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict dest,
					const void *restrict src,
					int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dst;
	unsigned char	*sc;
	size_t			i;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = 0;
	ch = c;
	while (i < n)
	{
		dst[i] = sc[i];
		if (sc[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
