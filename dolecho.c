/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolecho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:08:17 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/21 15:43:23 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		dolecho(t_f *strct)
{
	int i;
	int c;

	c = 0;
	i = findenv(strct, 5);
	if (i != 1000)
	{
		while (strct->env[i][c] != '=')
			c++;
		c++;
		while (strct->env[i][c] != '\0')
		{
			ft_putchar(strct->env[i][c]);
			c++;
		}
	}
	ft_putchar('\n');
	return (0);
}
