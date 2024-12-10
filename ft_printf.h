/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:24:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/09 21:31:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define COMANDS = "cspdiuxX%"

typedef struct s_print
{
	char			*original;
	char			*replaciment;
	struct s_comand	*comand;
}					t_print;

typedef struct s_comand
{
	char	flag;
	int		lenght;
	char	prcision;
	int		nu_precision;
	char	type;
}			t_comand;

int		ft_printf(const char *format, ...);
char	*translate_characters(t_print print, va_list args, char type);
char	*translate_digits(t_print print, va_list args, char type);
char	*translate_udigits(t_print print, va_list args, char type);

#endif

