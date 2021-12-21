/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:10:07 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/21 18:46:24 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **a)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		*a = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		write(1, "sa\n", 3);
	}
}

void	ft_swap_b(t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*b) > 1)
	{
		aux = *b;
		*b = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "sb\n", 3);
	}
}

void	ft_swap(t_list **a, t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		aux = *a;
		*a = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		aux = *b;
		*b = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "ss\n", 3);
	}
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*b) > 0)
	{
		aux = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, aux);
		write(1, "pa\n", 3);
	}
}

void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 0)
	{
		aux = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, aux);
		write(1, "pb\n", 3);
	}
}
