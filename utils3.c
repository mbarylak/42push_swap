/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:56:18 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/30 19:37:54 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list **a)
{
	t_list	*aux;
	int		min;

	aux = *a;
	min = aux->n;
	while (aux != NULL)
	{
		if (min > aux->n)
			min = aux->n;
		aux = aux->next;
	}
	return (min);
}

int	ft_until_min(t_list **a, int min)
{
	int		pos;
	t_list	*aux;

	aux = *a;
	pos = 0;
	while (aux != NULL)
	{
		if (aux->n == min)
			break ;
		aux = aux->next;
		pos++;
	}
	return (pos);
}

void	ft_min_2_top(t_list **a, int pos)
{
	int	min;

	min = ft_min(a);
	if (pos > (ft_lstsize(*a) / 2))
	{
		while (pos > 0 && (*a)->n != min)
		{
			pos--;
			ft_rev_rotate_a(a);
		}
	}
	else
	{
		while (pos > 0 && (*a)->n != min)
		{
			pos--;
			ft_rotate_a(a);
		}
	}
}
