/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:14:40 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:30:33 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ctwo(char *text, t_f *strct)
{
	strct->countli++;
	if (checkquo(text, strct->countli) == 1)
	{
		while (text[strct->countli] != '\'' && text[strct->countli] != '\0')
		{
			strct->countli++;
			strct->countlc++;
		}
		strct->countli++;
	}
	return (0);
}

int		cone(char *text, t_f *strct)
{
	strct->countli++;
	if (checkquo(text, strct->countli) == 1)
	{
		while (text[strct->countli] != '"' && text[strct->countli] != '\0')
		{
			strct->countli++;
			strct->countlc++;
		}
		strct->countli++;
	}
	return (0);
}

int		countl(char *text, t_f *strct)
{
	strct->countli = 0;
	strct->countlc = 0;
	while (text[strct->countli] != '\0')
	{
		if (checkforend(text, strct->countli, strct) == 0)
			return (0);
		else if (text[strct->countli] == '"')
			cone(text, strct);
		else if (text[strct->countli] == '\'')
			ctwo(text, strct);
		else if (text[strct->countli] == ' ')
			cthree(text, strct, 1);
		else if (text[strct->countli] == '\t')
			cthree(text, strct, 2);
		else
			cthree(text, strct, 3);
	}
	return (0);
}

int		checkforend(char *text, int i, t_f *strct)
{
	while (text[i] != '\0')
	{
		if (text[i] != ' ' && text[i] != '\t' && text[i] != '"'
			&& text[i] != '\'' && text[i] != '\0' && text[i] != '\n')
			return (1);
		else if (text[i] == '"' && checkquo(text, i + 1) == 0)
		{
			if (strct->duo == 0 && strct->quo == 0)
				strct->duo = 11;
			else if (strct->duo == 0)
				strct->duo = 21;
		}
		else if (text[i] == '\'' && checkquo(text, i + 1) == 0)
		{
			if (strct->quo == 0 && strct->duo == 0)
				strct->quo = 12;
			else if (strct->quo == 0)
				strct->quo = 22;
		}
		i++;
	}
	return (0);
}

int		checkemp(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] != ' ' && text[i] != '\t'
			&& text[i] != '\n' && text[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}
