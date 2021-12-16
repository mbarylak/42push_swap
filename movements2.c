/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:32:10 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/16 19:11:20 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **a)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*b) > 1)
	{
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_rotate(t_list **a, t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux->next = NULL;
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rr\n", 3);
	}
}

void	ft_rev_rotate_a(t_list **a)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		last = ft_lstlast(*a);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
		write(1, "rra\n", 4);
	}
}

void	ft_rev_rotate_b(t_list **b)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(*b) > 1)
	{
		aux = *b;
		last = ft_lstlast(*b);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b, last);
		write(1, "rrb\n", 4);
	}
}
