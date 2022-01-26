/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:51:25 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/26 17:30:18 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_change_value(t_list *a, int min, int value)
{
	while (a != NULL)
	{
		if (a->n == min && a->flag != 1)
		{
			a->n = value;
			a->flag = 1;
		}
		a = a->next;
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

int	ft_until_nbr(t_list **a, int nbr)
{
	t_list	*aux;
	int		pos;

	aux = *a;
	pos = 0;
	while (aux != NULL)
	{
		if (aux->n == nbr)
			break ;
		aux = aux->next;
		pos++;
	}
	return (pos);
}

void	ft_2_the_top_a(t_list **a, int n)
{
	int	pos;

	pos = ft_until_nbr(a, n);
	if (pos == 1)
		ft_swap_a(a);
	else if (pos > (ft_lstsize(*a) / 2))
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

void	ft_2_the_top_b(t_list **b, int n)
{
	int	pos;

	pos = ft_until_nbr(b, n);
	if (pos == 1)
		ft_swap_b(b);
	else if (pos > (ft_lstsize(*b) / 2))
	{
		while ((*b)->n != n)
			ft_rev_rotate_b(b);
	}
	else
	{
		while ((*b)->n != n)
			ft_rotate_b(b);
	}
}
