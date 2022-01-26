/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:57 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/26 18:29:07 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_pile(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_swap_a(a);
	else if (size == 3)
		ft_order_3(a);
	else if (size > 3 && size <= 5)
		ft_order_5(a, b);
	else if (size > 5 && size <= 10)
		ft_order_10(a, b);
	else if (size > 10)
		ft_order_big(a, b);
}

void	ft_add_nbr(char *s, t_list **a)
{
	int	nbr;

	nbr = ft_atoi(s);
	ft_repcheck(a, nbr);
	ft_lstadd_back(a, ft_lstnew(nbr));
	free(s);
}

void	ft_pile_up(int argc, char **argv, t_list **a)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		i = 0;
		while (argv[x][y])
		{
			j = 0;
			while (ft_isspace(argv[x][y]) && argv[x][y++])
				i++;
			while ((ft_isdigit(argv[x][y]) || ft_issign(argv[x][y])) \
					&& argv[x][y++])
				j++;
			if (j > 0)
				ft_add_nbr(ft_substr(argv[x], i, j + i), a);
			i = i + j;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;


	if (argc == 1)
		exit(0);
	ft_input_error(argc, argv, 0);
	ft_pile_up(argc, argv, &a);
	ft_is_sorted(&a);
	ft_revalue_lst(a);
	ft_sort_pile(&a, &b);
	ft_lstclear(&a);
	return (0);
}
