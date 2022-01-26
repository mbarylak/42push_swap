/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:47:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/26 17:40:03 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pass_2_array(t_list *lst, int size)
{
	int		*ar;
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	ar = malloc(size * sizeof(int));
	while (i < size)
	{
		ar[i] = aux->n;
		i++;
		aux = aux->next;
	}
	return (ar);
}

int	ft_find_hold_top(int *ar, int inf, int sup, int size)
{
	int	i;
	int	hold_top;

	i = 0;
	hold_top = 0;
	while (i < size)
	{
		if (ar[i] >= inf && ar[i] <= sup)
		{
			hold_top = ar[i];
			break ;
		}
		i++;
	}
	return (hold_top);
}

int	ft_find_hold_bot(int *ar, int inf, int sup, int size)
{
	int	hold_bot;
	int	i;

	i = size;
	hold_bot = 0;
	while (i >= 0)
	{
		i--;
		if (ar[i] >= inf && ar[i] <= sup)
		{
			hold_bot = ar[i];
			break ;
		}
	}
	return (hold_bot);
}

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
	if (pos1 > pos2)
		return (hold_top);
	else if (pos1 == pos2)
	{
		if (hold_top <= hold_bot)
			return (hold_top);
		else
			return (hold_bot);
	}
	return (hold_bot);
}

void	ft_search_chunk(t_list **a, t_list **b, int inf, int sup)
{
	int	*ar;
	int	hold_top;
	int	hold_bot;
	int	hold;
	int	size;

	size = ft_lstsize(*a);
	if (size != 1)
	{
		ar = ft_pass_2_array(*a, size);
		hold_top = ft_find_hold_top(ar, inf, sup, size);
		hold_bot = ft_find_hold_bot(ar, inf, sup, size);
		hold = ft_top_or_bot(a, hold_top, hold_bot);
		ft_2_the_top_a(a, hold);
		free(ar);
	}
	ft_push_b(a, b);
}
