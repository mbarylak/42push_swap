/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:15:03 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/19 17:12:56 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_3(t_list **a)
{
	t_list	*aux;

	aux = *a;
	if (aux->next->n < aux->next->next->n && aux->next->next->n > aux->n && \
			aux->n > aux->next->n)
		ft_swap_a(a);
	else if (aux->n > aux->next->n && aux->next->n > aux->next->next->n && \
			aux->next->next->n < aux->n)
	{
		ft_swap_a(a);
		ft_rev_rotate_a(a);
	}
	else if (aux->n > aux->next->n && aux->next->n < aux->next->next->n && \
			aux->next->next->n < aux->n)
		ft_rotate_a(a);
	else if (aux->n < aux->next->n && aux->next->n > aux->next->next->n && \
			aux->next->next->n > aux->n)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (aux->n < aux->next->n && aux->next->n > aux->next->next->n && \
			aux->next->next->n < aux->n)
		ft_rev_rotate_a(a);
}

int	ft_min2(t_list *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

void	ft_order_5(t_list **a, t_list **b)
{
	int	min;

	while (ft_lstsize(*a) != 3)
	{
		min = ft_min2(*a);
		ft_2_the_top(a, min);
		ft_push_b(a, b);
	}
	ft_order_3(a);
	while (ft_lstsize(*b) > 0)
		ft_push_a(a, b);
}

void	ft_order_10(t_list **a, t_list **b)
{
	int	min;

	while (ft_lstsize(*a) != 5)
	{
		min = ft_min2(*a);
		ft_2_the_top(a, min);
		ft_push_b(a, b);
	}
	ft_order_5(a, b);
	while (ft_lstsize(*b) > 0)
		ft_push_a(a, b);
}
