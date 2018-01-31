/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:25:07 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/21 16:06:32 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		checkone(t_f *strct)
{
	int	i;

	i = 0;
	if (ft_strcmp(strct->com, "cd") == 0)
		pathmaker(strct);
	else if (ft_strcmp(strct->com, "setenv") == 0)
		ssetenv(strct);
	else if (ft_strcmp(strct->com, "unsetenv") == 0)
		unssetenv(strct);
	else if (strct->com[0] == '/')
	{
		if (doit(strct) != 0)
			ft_putstr("Command not found\n");
	}
	else
	{
		if (foldercheck(strct) == 0 && strct->kk != 7)
			ft_putstr("Command not found\n");
	}
	return (0);
}

int		checkcommand(t_f *strct)
{
	int i;

	i = 0;
	if (ft_strcmp(strct->com, "exit") == 0)
		return (0);
	else if ((ft_strcmp(strct->com, "env") == 0)\
		|| (ft_strcmp(strct->com, "/usr/bin/env") == 0))
	{
		if (strct->argv[1] != NULL)
			ft_putstr("error\n");
		else
		{
			while (i < strct->i)
			{
				ft_putstr(strct->env[i]);
				if (i != strct->i - 1)
					ft_putchar('\n');
				i++;
			}
		}
	}
	else
		checkone(strct);
	return (1);
}
