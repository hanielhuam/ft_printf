/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_udigits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:47:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/15 19:25:07 by hmacedo-         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*transl_ud(char *str, unsigned int n, char *base)
{
	char	*number;
	char	*sub;
	char	*result;

	number = ft_ulitoa_base((unsigned long int) n, base);
	sub = ft_substr(str, 1, ft_strlen(str) - 1);
	result = ft_strjoin(number, sub);
	free(number);
	free(sub);
	return (result);
}

static char	*transl_p(char *str, void *p, char *base)
{
	char	*temp;
	char	*num;
	char	*sub;
	char	*result;

	if (!p)
		temp = ft_strdup("(null)");
	else
	{
		temp = ft_strdup("0x");
		num = ft_ulitoa_base((unsigned long int)p, base);
		result = ft_strjoin(temp, num);
		free(temp);
		free(num);
		temp = result;
	}
	sub = ft_substr(str, 1, ft_strlen(str) - 1);
	result = ft_strjoin(temp, sub);
	free(temp);
	free(sub);
	return (result);
}

char	*translate_udigits(t_print *print, va_list args, char type)
{
	if (type == 'u')
		return transl_ud(print->original, va_arg(args, unsigned int), BASE_10);
	if (type == 'x')
		return transl_ud(print->original, va_arg(args, unsigned int), BASE_16);
	if (type == 'X')
		return transl_ud(print->original, va_arg(args, unsigned int), BASE_16U);
	if (type == 'p')
		return transl_p(print->original, va_arg(args, void *), BASE_16);
	return (ft_strdup(print->original));
}
