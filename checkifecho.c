/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkifecho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:47:47 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/21 15:43:59 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		checkifecho(char *text)
{
	int	i;
	int	c;

	i = 0;
	while (text[i] == ' ' || text[i] == '\t')
		i++;
	if (text[i] == 'e')
		c = 1;
	else
		return (0);
	if (text[i + 1] == 'c')
		c = 1;
	else
		return (0);
	if (text[i + 2] == 'h')
		c = 1;
	else
		return (0);
	if (text[i + 3] == 'o')
		c = 1;
	else
		return (0);
	return (1);
}

int		validateecho(char *text, t_f *strct)
{
	int i;

	i = 5;
	if (strct->text[5] == '$')
	{
		dolecho(strct);
		return (0);
	}
	while (strct->text[i] != '\0')
	{
		ft_putchar(strct->text[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
