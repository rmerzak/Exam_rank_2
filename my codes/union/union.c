/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:01:43 by rmerzak           #+#    #+#             */
/*   Updated: 2022/02/16 22:04:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
int ft_is_there(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void ft_print_c(char *argv, char *p,int *j)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_there(p,argv[i]))
		{
			write(1,&argv[i],1);
			p[(*j)] = argv[i];
			(*j)++;
		}
		i++;
	}
}

int	main(int argc,char **argv)
{
	char	p[1024];
	int		i;
	int		*j;

	i = 0;
	if (argc == 3) 
	{
		ft_print_c(argv[1],p,&i);
		ft_print_c(argv[2],p,&i);
	}
	write(1, "\n", 1);
	return (0);
}
