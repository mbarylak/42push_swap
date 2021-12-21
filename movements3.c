/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:27:38 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/21 18:26:39 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*aux;

	if (ft_lstsize(*a) > 1 && ft_lstsize(*b))
	{
		aux = *a;
		last = ft_lstlast(*a);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
		aux = *b;
		last = ft_lstlast(*b);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
		write(1, "rrr\n", 4);
	}
}
