/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:23 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:13:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *restrict dest,
					const char *restrict src,
					size_t dstsize)
{
	char		*dst;
	const char	*sc;
	size_t		n;
	size_t		dlen;

	dst = dest;
	sc = src;
	n = dstsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dest;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dst++ = *sc;
			n--;
		}
		sc++;
	}
	*dst = '\0';
	return (dlen + (sc - src));
}
