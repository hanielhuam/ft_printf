/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/15 18:28:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*translate_d(char *str, int n)
{
	char	*number;
	char	*sub;
	char	*result;

	number = ft_litoa_base((long int) n, BASE_10);
	sub = ft_substr(str, 1, ft_strlen(str) - 1);
	result = ft_strjoin(number, sub);
	free(number);
	free(sub);
	return (result);
}

char	*translate_digits(t_print *print, va_list args)
{
	return translate_d(print->original, va_arg(args, int));
}
