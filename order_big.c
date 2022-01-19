/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:57:16 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/19 17:33:44 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_order_big(t_list **a, t_list **b)
{
	int	size;
	int	i;
	int	max;

	size = ft_lstsize(*a);
	ft_fill_b(a, b, size);
	i = 0;
	while (i < size)
	{
		max = ft_max(*b);
		ft_2_the_top_b(b, max);
		ft_push_a(a, b);
		i++;
	}
}
