/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:05:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/15 18:15:24 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*translate_c(char *str, int c)
{
	char	*dup;

	if (!c)
		return ft_substr(str, 1, ft_strlen(str) - 1);
	dup = ft_strdup(str);
	dup[0] = c;
	return (dup);
}

static char	*translate_s(char *str, char *s)
{
	char	*temp;
	char	*sub;
	char	*result;

	if (!s)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(s);
	sub = ft_substr(str, 1, ft_strlen(str) - 1);
	result = ft_strjoin(temp, sub);
	free(temp);
	free(sub);
	return (result);
}

char	*translate_characters(t_print *print, va_list args, char type)
{
	if (type == 'c')
		return translate_c(print->original, va_arg(args, int));
	if (type == '%')
		return translate_c(print->original, '%');
	if (type == 's')
		return translate_s(print->original, va_arg(args, char*));
	return (ft_strdup(print->original));
}
