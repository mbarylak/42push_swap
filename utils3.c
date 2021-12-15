/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:56:18 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/15 20:28:05 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *a)
{
	int		min;

	min = INT_MAX;
	while (a != NULL)
	{
		if (min > a->n && a->flag != 1)
			min = a->n;
		a = a->next;
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

void	ft_2_the_top(t_list **a, int pos, int n)
{
	if (pos > (ft_lstsize(*a) / 2))
	{
		while ((*a)->n != n)
			ft_rev_rotate_a(a);
	}
	else
	{
		while ((*a)->n != n)
			ft_rotate_a(a);
	}
}

void	ft_change_value(t_list *a, int min, int value)
{
	while (a != NULL)
	{
		if ((a)->n == min && (a)->flag != 1)
		{
			(a)->n = value;
			(a)->flag = 1;
		}
		(a) = (a)->next;
	}
}

void	ft_revalue_lst(t_list *a)
{
	int	value;

	value = 0;
	while (value < ft_lstsize(a))
	{
		ft_change_value(a, ft_min(a), value);
		value++;
	}
}
