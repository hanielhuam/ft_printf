/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:45:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 07:39:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	signal;
	int		result;

	while (ft_isspace(*nptr))
		nptr++;
	signal = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			signal = -1;
	}
	result = 0;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	return (result * signal);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("\n\f-199a4"));
	printf("%d\n", atoi("\n\f-199a4"));
	return (0);
}*/
