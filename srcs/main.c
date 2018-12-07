/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 15:35:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

void	ft_free(t_list *elem, char *finish[1])
{
	if (elem->next)
		ft_free(elem->next, finish);
	free(elem->data);
	elem->data = NULL;
	elem->next = NULL;
	free(elem);
	if (*finish)
		free(*finish);
}

int		main(int ac, char **av)
{
	char	str[BUFF_SIZE + 1];
	char	*finish[1];
	t_count	piece;
	t_list	*elem;
	t_list	*tmp;

	tmp = NULL;
	elem = NULL;
	piece.point = 0;
	if (!(piece.n = 0) && ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (-1);
	}
	if (!(piece.hashtag = 0) && ((ft_verif_args(av, str, &piece) == -1) ||
	!(elem = ft_verif_lst(elem, tmp, str))))
	{
		ft_putendl("error");
		return (0);
	}
	free(tmp);
	ft_do_it(elem, finish);
	write(1, finish[0], ft_strlen(finish[0]));
	ft_free(elem, finish);
	return (0);
}
