/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:21:26 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/26 19:28:48 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			while (((argv[x][y] >= '0' && argv[x][y] <= '9') || \
					ft_issign(argv[x][y])) && argv[x][y++])
				j++;
			if (j > 0)
				ft_add_a(ft_substr(argv[x], i, j + i), a);
			i = i + j;
		}
		x++;
	}
}

void	ft_add_a(char *s, t_list **a)
{
	int	nbr;

	nbr = ft_atoi(s);
	ft_repcheck(a, nbr);
	ft_lstadd_back(a, ft_lstnew(nbr));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*aux;

	if (argc == 1)
		ft_error();
	ft_input_error(argc, argv, 0);
	ft_pile_up(argc, argv, &a);
	ft_is_sorted(&a);
	ft_rev_rotate_a(&a);
	aux = a;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
	return (0);
}
