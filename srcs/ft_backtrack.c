/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 15:35:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		ft_conversion(t_list *elem, int size)
{
	char	*dat;
	int		op;

	op = ft_len(elem->data);
	if (!(dat = (char*)malloc(sizeof(char) * ((size + 1) * size + 1))))
		return (0);
	if (size <= elem->pos1 / op || size <= elem->pos1 % op || size <= elem->pos2 /
	op || size <= elem->pos2 % op || size <= elem->pos3 / op || size <= elem->pos3
	% op || size <= elem->pos4 / op || size <= elem->pos4 % op)
	{
		free(dat);
		return (0);
	}
	dat = ft_set_carre(dat, (size + 1) * size, size + 1);
	elem->pos1 = (size + 1) * (elem->pos1 / op) + elem->pos1 % op;
	elem->pos2 = (size + 1) * (elem->pos2 / op) + elem->pos2 % op;
	elem->pos3 = (size + 1) * (elem->pos3 / op) + elem->pos3 % op;
	elem->pos4 = (size + 1) * (elem->pos4 / op) + elem->pos4 % op;
	dat[elem->pos1] = 'A' + elem->letter;
	dat[elem->pos2] = 'A' + elem->letter;
	dat[elem->pos3] = 'A' + elem->letter;
	dat[elem->pos4] = 'A' + elem->letter;
	free(elem->data);
	elem->data = dat;
	return (1);
}

int		ft_placement(t_list *elem, char *carre)
{
	if (carre[elem->pos1] == '.' && carre[elem->pos2] == '.' &&
	carre[elem->pos3] == '.' && carre[elem->pos4] == '.')
	{
		carre[elem->pos1] = elem->letter + 'A';
		carre[elem->pos2] = elem->letter + 'A';
		carre[elem->pos3] = elem->letter + 'A';
		carre[elem->pos4] = elem->letter + 'A';
		return (1);
	}
	return (0);
}

int		ft_clean(char c, char *carre)
{
	int i;

	i = -1;
	while (carre[++i])
		if (carre[i] == c)
			carre[i] = '.';
	return (1);
}

int		ft_decale(t_list *elem, int i)
{
	if (!(ft_decale_right(elem, elem->data, 'A' + elem->letter, i)))
	{
		if (!(ft_decale_down(elem, elem->data, 'A' + elem->letter, i)))
		{
			while (ft_decale_up(elem, elem->data, 'A' + elem->letter, i)
			|| ft_decale_left(elem, elem->data, 'A' + elem->letter, i))
				;
			return (0);
		}
		while (ft_decale_left(elem, elem->data, 'A' + elem->letter, i))
			;
	}
	return (1);
}

int		ft_backtrack(t_list *elem, int i, char *carre, char *finish[1])
{
	if (elem == NULL && (finish[0] = ft_strdup(carre)))
		free(carre);
	if (finish[0])
		return (1);
	if (ft_conversion(elem, i))
		while (1)
		{
			if (ft_placement(elem, carre))
				if (ft_backtrack(elem->next, i, carre, finish))
					return (1);
			if (ft_clean(elem->letter + 'A', carre) && (!ft_decale(elem, i)))
				break ;
		}
	if (elem->letter == 0 && (++i))
	{
		free(carre);
		if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
			return (0);
		carre = ft_set_carre(carre, (i + 1) * i, i + 1);
		if ((ft_backtrack(elem, i, carre, finish)))
			return (1);
	}
	return (0);
}
