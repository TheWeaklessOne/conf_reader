/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:14:49 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/01 17:30:33 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int						ft_error(const char *msg, ...)
{
	va_list				args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);
	return (msg ? -msg[0] : -255);
}

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	register size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	register size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (0);
}
