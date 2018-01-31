/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:52:38 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:27:02 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		findone(t_f *strct)
{
	while (strct->text[strct->fk] == strct->env[strct->fh][strct->fw])
	{
		strct->fk++;
		strct->fw++;
	}
	return (0);
}

int		findenv(t_f *strct, int i)
{
	i++;
	while (strct->text[i] == ' ')
		i++;
	strct->fk = i;
	strct->fa = strct->text[i];
	strct->fh = 0;
	strct->fw = 0;
	while (strct->fh < strct->i - 2)
	{
		if (strct->fa == strct->env[strct->fh][0])
		{
			if (strct->text[strct->fk] == strct->env[strct->fh][strct->fw])
				findone(strct);
			if ((strct->text[strct->fk] == ' ' || strct->text[strct->fk]\
				== '\0') && strct->env[strct->fh][strct->fw] == '=')
				return (strct->fh);
			strct->fk = i;
			strct->fw = 0;
		}
		strct->fh++;
	}
	return (1000);
}

int		maketwo(t_f *strct)
{
	int k;

	k = -1;
	while (strct->text[strct->mi] != '\0')
	{
		if (strct->text[strct->mi] == ' ')
		{
			if (strct->text[strct->mi] == ' ')
			{
				if (++k > 1)
					break ;
			}
			while (strct->text[strct->mi] == ' ')
				strct->mi++;
			if (strct->mc > 0)
			{
				strct->new[strct->mc] = '=';
				strct->mc++;
			}
		}
		strct->new[strct->mc] = strct->text[strct->mi];
		strct->mc++;
		strct->mi++;
	}
	return (0);
}

char	*makeit(t_f *strct)
{
	int k;

	k = -1;
	strct->omi = strct->mi;
	strct->omc = strct->mc;
	while (strct->text[strct->mi] != '\0')
	{
		if (strct->text[strct->mi] == ' ')
		{
			if (++k > 1)
				break ;
		}
		while (strct->text[strct->mi] == ' ')
		{
			strct->mi++;
		}
		strct->mc++;
		strct->mi++;
	}
	strct->new = (char *)malloc(sizeof(char) * strct->mc + 2);
	strct->new[strct->mc + 1] = '\0';
	strct->mi = strct->omi;
	strct->mc = strct->omc;
	maketwo(strct);
	return (0);
}
