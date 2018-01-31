/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:56:45 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/26 16:09:23 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		makecom(t_f *strct, char *text)
{
	int i;

	i = 0;
	while (text[i] != ' ' && text[i] != '\0')
		i++;
	strct->com = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (text[i] != ' ' && text[i] != '\0')
	{
		strct->com[i] = text[i];
		i++;
	}
	strct->com[i] = '\0';
	return (0);
}

int		makestri(t_f *strct, int c, int i, char *text)
{
	int f;
	int a;

	f = 0;
	a = i;
	while (text[i] != ' ' && text[i] != '\0')
	{
		i++;
		f++;
	}
	strct->argv[c] = (char *)malloc(sizeof(char) * f);
	i = a;
	f = 0;
	while (text[i] != ' ' && text[i] != '\0')
	{
		strct->argv[c][f] = text[i];
		i++;
		f++;
	}
	strct->argv[c][f] = '\0';
	return (0);
}

t_f		*separate(t_f *strct, char *text)
{
	makecom(strct, text);
	strct->sepi = separator(text);
	strct->argvi = strct->sepi;
	strct->argv = (char **)malloc(sizeof(char *) * strct->sepi + 1);
	strct->argv[strct->sepi] = NULL;
	strct->argv[0] = ft_strdup(strct->com);
	if (strct->sepi == 1)
		return (strct);
	strct->sepi = 0;
	strct->sepc = 1;
	while (text[strct->sepi] != ' ')
		strct->sepi++;
	strct->sepi++;
	while (text[strct->sepi] != '\0')
	{
		makestri(strct, strct->sepc, strct->sepi, text);
		strct->sepc++;
		while (text[strct->sepi] != ' ' && text[strct->sepi] != '\0')
			strct->sepi++;
		if (text[strct->sepi] == '\0')
			return (0);
		strct->sepi++;
	}
	return (strct);
}
