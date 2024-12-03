/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:05:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/02 17:24:29 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*translate_c(char *str, int c)
{
	char	*dup;
	dup = ft_strdup(str);
	dup[0] = c;
	return (dup);
}

char	*translate_s(char *str, char *s)
{
	char	*result;

	if (!s)
		result = strdup("(nill)");
	else
		result = s;
	result = ft_strjoin(result, ft_substr(str, 1, ft_strlen(str) - 1));
	return (result);
}
