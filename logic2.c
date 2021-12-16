/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:49:51 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/16 22:26:20 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_top_or_bot(t_list **a, int hold_top, int hold_bot)
{
	int	pos1;
	int	pos2;
	int	size;

	size = ft_lstsize(*a) / 2;
	pos1 = ft_until_nbr(a, hold_top);
	pos2 = ft_until_nbr(a, hold_bot);
	pos1 = ft_abs(size - pos1);
	pos2 = ft_abs(size - pos2);
	if (pos1 == pos2)
	{
		if (hold_top < hold_bot)
			return (hold_top);
		else
			return (hold_bot);
	}
	if (pos1 > pos2)
		return (hold_top);
	return (hold_bot);
}

void	ft_search_chunk(t_list **a, t_list **b, int inf, int sup)
{
	int	hold_top;
	int	hold_bot;
	int	hold;
	int	*ar;

	if (ft_lstsize(*a) != 1)
	{
		ar = ft_pass_2_array(a);
		hold_top = ft_find_hold_top(ar, inf, sup);
		hold_bot = ft_find_hold_bot(ar, inf, sup);
		hold = ft_top_or_bot(a, hold_top, hold_bot);
		ft_2_the_top(a, hold);
		free(ar);
	}
	ft_push_b(a, b);
}

void	ft_fill_b(t_list **a, t_list **b, int size)
{
	int	c_size;
	int	i;
	int	inf;
	int	sup;

	c_size = ft_chunk_div(a);
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
		}
		i--;
	}
}

int	ft_max(t_list *b)
{
	int	max;

	max = INT_MIN;
	while (b != NULL)
	{
		if (max < b->n)
			max = b->n;
		b = b->next;
	}
	return (max);
}
