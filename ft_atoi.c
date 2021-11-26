/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:24:52 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/26 18:40:12 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == ' ');
}

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_ismax(int sign, unsigned long long nbr)
{
	if (nbr > INT_MAX || nbr > (INT_MIN * -1))
		ft_error();
	return (sign * nbr);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	unsigned long long	nbr;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(s[i]))
		i++;
	if (ft_issign(s[i]))
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		ft_error();
	while (ft_isdigit(s[i]))
	{
		nbr = nbr * 10;
		nbr = nbr + (s[i] - '0');
		i++;
	}
	return (ft_ismax(sign, nbr));
}
