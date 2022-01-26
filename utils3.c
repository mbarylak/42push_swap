/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:24:45 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/25 20:25:59 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_chunk_div(t_list **a, int n)
{
	if (*a)
	{
		return (ft_lstsize(*a) / n);
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0 && n > INT_MIN)
		return (n * -1);
	return (n);
}
