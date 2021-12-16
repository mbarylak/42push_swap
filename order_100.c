/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:57:16 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/16 22:16:19 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_100(t_list **a, t_list **b)
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
		ft_2_the_top(b, max);
		ft_push_a(a, b);
		i++;
	}
}
