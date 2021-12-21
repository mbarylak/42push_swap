/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:34:50 by mbarylak          #+#    #+#             */
/*   Updated: 2021/12/21 21:02:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_repcheck(t_list **a, int	nbr)
{
	t_list	*aux;

	aux = *a;
	if (*a != NULL)
	{
		while (aux != NULL)
		{
			if (aux->n == nbr)
				ft_error();
			aux = aux->next;
		}
	}
}

void	ft_is_sorted(t_list **a)
{
	t_list	*aux;

	aux = *a;
	while (aux->next)
	{
		if (aux->n < aux->next->n)
			aux = aux->next;
		else
			break ;
	}
	if (aux->next == NULL)
		exit(0);
}

void	ft_input_error(int argc, char **argv, int flag)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		ft_empty_str(argv[i]);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_issign(argv[i][j]) \
						&& !ft_isspace(argv[i][j]))
				ft_error();
			else if (ft_isdigit(argv[i][j]))
			{	
				flag = 1;
				if (argv[i][j + 1] && ft_issign(argv[i][j + 1]))
					ft_error();
			}
			j++;
		}
		if (!flag)
			ft_error();
		i++;
	}
}

void	ft_empty_str(char *s)
{
	if (ft_strlen(s) == 0)
		ft_error();
}
