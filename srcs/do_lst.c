/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:15:31 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 15:35:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

t_list	*ft_lstnew(char *data, int i)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!(data))
		elem->data = NULL;
	else
	{
		if (!(elem->data = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		ft_memcpy(elem->data, data, 20, i);
		elem->data[20] = '\0';
	}
	elem->next = NULL;
	return (elem);
}

void	ft_lstnext(t_list **begin, char *data, int k)
{
	if (!(*begin = ft_lstnew(data, k)))
		free(begin);
}

t_list	*ft_lst_split(t_list *elem, char *str)
{
	int		i;
	int		k;
	t_list	*begin;

	i = 0;
	k = 0;
	ft_lstnext(&elem, &str[i], k++);
	i += 21;
	begin = elem;
	while (i < ft_strlen(str))
	{
		ft_lstnext(&elem->next, &str[i], k++);
		i += 21;
		elem = elem->next;
	}
	return (begin);
}

t_list	*ft_verif_lst(t_list *piece, t_list *tmp, char *str)
{
	t_list	*begin;

	piece = ft_lst_split(tmp, str);
	free(tmp);
	begin = piece;
	while (piece)
	{
		if (ft_check_neib(piece) == -1)
			return (NULL);
		piece = piece->next;
	}
	free(piece);
	return (begin);
}
