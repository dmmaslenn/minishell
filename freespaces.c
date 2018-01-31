/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freespaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:25:54 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:23:30 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		checkquo(char *good, int i)
{
	if (good[i - 1] == '"')
	{
		while (good[i] != '"' && good[i] != '\0')
			i++;
	}
	else
		while (good[i] != '\'' && good[i] != '\0')
			i++;
	if (good[i] == '\0')
		return (0);
	else
		return (1);
}

int		freethree(t_f *strct, int i)
{
	if (i == 1)
	{
		if (strct->freei != 0 && strct->txt[strct->freei - 1] != ' ')
		{
			strct->text[strct->freec] = ' ';
			strct->freec++;
		}
		while (strct->txt[strct->freei] == ' ' && \
		strct->txt[strct->freei] != '\0')
			strct->freei++;
	}
	else if (i == 2)
	{
		if (strct->freei != 0 && strct->txt[strct->freei - 1] != ' ')
		{
			strct->text[strct->freec] = ' ';
			strct->freec++;
		}
		while (strct->txt[strct->freei] == '\t' \
		&& strct->txt[strct->freei] != '\0')
			strct->freei++;
	}
	return (0);
}

int		freetwo(t_f *strct)
{
	strct->freei++;
	if (checkquo(strct->txt, strct->freei) == 1)
	{
		while (strct->txt[strct->freei] != '\'' \
		&& strct->txt[strct->freei] != '\0')
		{
			strct->text[strct->freec] = strct->txt[strct->freei];
			strct->freei++;
			strct->freec++;
		}
		strct->freei++;
	}
	return (0);
}

int		freeone(t_f *strct)
{
	strct->freei++;
	if (checkquo(strct->txt, strct->freei) == 1)
	{
		while (strct->txt[strct->freei] != '"' \
		&& strct->txt[strct->freei] != '\0')
		{
			strct->text[strct->freec] = strct->txt[strct->freei];
			strct->freei++;
			strct->freec++;
		}
		strct->freei++;
	}
	return (0);
}

char	*freespaces(t_f *strct)
{
	strct->freec = 0;
	countl(strct->txt, strct);
	strct->text = (char *)malloc(sizeof(char) * strct->countlc + 1);
	strct->text[strct->countlc] = '\0';
	while (strct->txt[strct->freei] != '\0')
	{
		if (checkforend(strct->txt, strct->freei, strct) == 0)
			return (0);
		else if (strct->txt[strct->freei] == '"')
			freeone(strct);
		else if (strct->txt[strct->freei] == '\'' \
		&& strct->txt[strct->freei] != '\0')
			freetwo(strct);
		else if (strct->txt[strct->freei] == ' ')
			freethree(strct, 1);
		else if (strct->txt[strct->freei] == '\t')
			freethree(strct, 2);
		else
		{
			strct->text[strct->freec] = strct->txt[strct->freei];
			strct->freei++;
			strct->freec++;
		}
	}
	return (0);
}
