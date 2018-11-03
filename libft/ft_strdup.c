/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:47 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:12:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*out;
	size_t	i;

	i = 0;
	if ((out = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)) == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		out[i] = src[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
