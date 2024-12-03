/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/02 18:45:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*translate_d(char *str, int n)
{
	char	*result;

	result = ft_itoa(n);
	result = ft_strjoin(result, ft_substr(str, 1, ft_strlen(str) - 1));
	return (result);
}

char	*translate_ud(char *str, unsigned int)
{
	char	*result;

	result = ft_uitoa(n);
	result = ft_strjoin(result, ft_substr(str, 1, ft_strlen(str) - 1));
	return (result);
}
