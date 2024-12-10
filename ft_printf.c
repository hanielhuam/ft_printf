/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/09 21:21:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_comand	*create_comand(char c)
{
	t_comand	*comand;
	
	comand = (t_comand *)malloc(sizeof(t_comand) * 1);
	if (!comand)
		return (NULL);
	comand->type = c;
	return (comand);
}

t_comand	*which_comand(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return create_comand(c);
	else
		return (NULL);
}

t_print	*creat_print(char *str)
{
	t_print	*print;
	
	print = (t_print *)malloc(sizeof(t_print) * 1);
	print->original = str;
	print->comand = which_comand(*str);
	return (print);
}

t_list	*to_t_list(char **matrix, int first)
{
	t_list	*list;
	t_print	*print;
	
	malloc	list = NULL;
	if (!first)
	{
		print = (t_print *)malloc(sizeof(t_print));
		print->original = *matrix++;
		print->comand = NULL;
		ft_lstadd_back(&list, ft_lstnew(print));
	}
	while (*matrix)
		ft_lstadd_back(&list, ft_lstnew(creat_print(*matrix++)));
	return (list);
}


void	translate(t_list *list, va_list args)
{
	t_print	*print;
	char	type;

	while (list)
	{
		print = (t_print *) list->content;
		if (print->comand)
		{
			type = print->comand->type;
			if (type == 'c' || type == '%' || type == 's')
				print->replaciment = translate_characters(print, args, type);
			if (type == 'd' || type == 'i')
				print->replaciment = translate_digits(print, args, type);
			if (type == 'u' || type == 'x' || type == 'X' || type == 'p')
				print->replaciment = translate_udigits(print, args, type);
		}
		else
			print->replaciment = print->original;
		list = list->next;
	}
}

int	show(t_list *list)
{
	char	*result;
	t_print	*print;
	int	count;

	print = (t_print *)list->content;
	result = ft_strdup(print->replaciment);
	list = list->next;
	while(list)
	{
		print = (t_print *)list->content;
		result = ft_strjoin(result, print->replaciment);
		list = list->next;
	}
	count = ft_strlen(result);
	write(1, result, count);
	return (count);
}

int     ft_printf(const char *format, ...)
{
	char	first;
	char	**matrix;
	t_list	*list_print;
	va_list	args;

	if (!format)
		return (-1);
	first = 0;
	if (*format != '%')
		first = 0;
	else
		first = 1;
	matrix = ft_separate(format, '%');
	if (!*matrix[0])
		return (-1);
	list_print = to_t_list(matrix, first);
	va_start(args, format);
	translate(list_print, args);
	va_end(args);
	return (show(list_print));
}

#include <stdio.h>

void	show_matrix(char **matrix)
{
	while (*matrix)
		printf("%s\n", *matrix++);
}

void	show_list(t_list *list)
{
	t_print	*print;

	while(list)
	{
		print = (t_print  *) list->content;
		printf("original: %s\n", print->original);
		if (print->comand)
			printf("comand: %c\n", print->comand->type);
		else
			printf("comand: (nill)\n");
		list = list->next;
	}
}

int	main(void)
{	
	ft_printf("%dHaniel%uHuam%iMacedo%cFerreira%%", 32, 42, 52, ' ');
	//printf("Haniel%H\n", 1);
	return (0);

