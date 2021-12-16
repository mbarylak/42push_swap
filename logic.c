/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:25:30 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/16 22:26:22 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pass_2_array(t_list **lst)
{
	int		*ar;
	int		i;
	int		size;
	t_list	*aux;

	i = 0;
	size = ft_lstsize(*lst);
	aux = *lst;
	ar = malloc(size + 1);
	while (i < size)
	{
		ar[i] = aux->n;
		i++;
		aux = aux->next;
	}
	ar[i] = -1;
	return (ar);
}

int	ft_find_hold_top(int *ar, int inf, int sup)
{
	int	i;
	int	hold_top;

	i = 0;
	hold_top = 0;
	while (ar[i])
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

int	ft_find_hold_bot(int *ar, int inf, int sup)
{
	int	hold_bot;
	int	i;

	i = 0;
	while (ar[i] != -1)
		i++;
	hold_bot = 0;
	while (i > 0)
	{
		if (ar[i] >= inf && ar[i] <= sup)
		{
			hold_bot = ar[i];
			break ;
		}
		i--;
	}
	return (hold_bot);
}

int	ft_chunk_div(t_list **a)
{
	if (*a)
	{
		return (ft_lstsize(*a) / 5);
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0 && n > INT_MIN)
		return (n * -1);
	return (n);
}
