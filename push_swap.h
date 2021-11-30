/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:21:51 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/30 20:30:59 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	struct s_list	*next;
	int				n;
	int				size;
}	t_list;

/* Utils */

int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_substr(const char *s, int start, int len);
int		ft_atoi(const char *s);
int		ft_isspace(int c);
int		ft_issign(int c);
int		ft_isdigit(int c);
int		ft_ismax(int sign, unsigned long long nbr);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_min(t_list **a);
int		ft_until_min(t_list **a, int min);
void	ft_min_2_top(t_list **a, int pos);

/* Parse & Pile up */

void	ft_pile_up(int argc, char **argv, t_list **a);
void	ft_add_a(char *s, t_list **a);
void	ft_sort_pile(t_list **a, t_list **b);

/* Error */

void	ft_error(void);
void	ft_repcheck(t_list **a, int nbr);
void	ft_is_sorted(t_list **a);
void	ft_input_error(int argc, char **argv, int flag);
void	ft_empty_str(char *s);

/* Movements */

void	ft_swap_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_swap(t_list **a, t_list **b);
void	ft_push_a(t_list **a, t_list **b);
void	ft_push_b(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_rotate(t_list **a, t_list **b);
void	ft_rev_rotate_a(t_list **a);
void	ft_rev_rotate_b(t_list **b);
void	ft_rev_rotate(t_list **a, t_list **b);

/* Logic */

void	ft_order_3(t_list **a);
void	ft_order_5(t_list **a, t_list **b);
void	ft_order_10(t_list **a, t_list **b);

#endif
