/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:26:20 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/20 15:04:38 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			separator(char *good)
{
	int		c;
	int		a;

	c = 0;
	a = 1;
	while (good[c] != '\0')
	{
		if (good[c] == ' ')
		{
			a++;
			while (good[c] == ' ' && good[c] != '\0')
				c++;
		}
		c++;
	}
	return (a);
}

char		*makep(t_f *strct)
{
	int		i;
	int		c;

	i = 7;
	c = 0;
	strct->p = ft_strnew(ft_strlen(strct->env[23]) - 6);
	while (strct->env[23][i] != '\0')
	{
		strct->p[c] = strct->env[23][i];
		c++;
		i++;
	}
	strct->p[c] = '\0';
	return (0);
}

int			additt(char *path)
{
	path[0] = '/';
	path[1] = 'n';
	path[2] = 'f';
	path[3] = 's';
	path[4] = '/';
	path[5] = '2';
	path[6] = '0';
	path[7] = '1';
	path[8] = '6';
	path[9] = '/';
	path[10] = 'd';
	path[11] = '/';
	path[12] = 'd';
	path[13] = 'm';
	path[14] = 'a';
	path[15] = 's';
	path[16] = 'l';
	path[17] = 'e';
	path[18] = 'n';
	path[19] = 'n';
	path[20] = '/';
	return (0);
}

int			printpath(char *path)
{
	int		i;

	i = 21;
	ft_putstr("~/");
	while (path[i] != '\0')
	{
		ft_putchar(path[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
