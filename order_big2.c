/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:13:17 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/26 17:32:52 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_b(t_list **a, t_list **b, int size)
{
	int	c_size;
	int	i;
	int	inf;
	int	sup;

	if (ft_lstsize(*a) > 100)
		c_size = ft_chunk_div(a, 11);
	else
		c_size = ft_chunk_div(a, 6);
	i = size;
	inf = 0;
	sup = c_size - 1;
	while (i > 0)
	{
		ft_search_chunk(a, b, inf, sup);
		if ((ft_lstsize(*b) != 0) && (ft_lstsize(*b) % c_size == 0) && \
				(ft_lstsize(*b) != size))
		{
			inf = inf + c_size;
			sup = sup + c_size;
			if (sup > size - 1)
				sup = size - 1;
		}
		i--;
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
