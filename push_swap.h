/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:59:49 by mbarylak          #+#    #+#             */
/*   Updated: 2022/01/26 18:19:01 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	int				flag;
	int				n;
}	t_list;

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

/* Atoi */

int		ft_isspace(int c);
int		ft_issign(int c);
int		ft_ismax(int sign, unsigned long long nbr);
int		ft_isdigit(int c);
int		ft_atoi(const char *s);

/* Errors */

void	ft_error(void);
void	ft_empty_str(char *s);
void	ft_input_error(int argc, char **argv, int flag);
void	ft_repcheck(t_list **a, int nbr);
void	ft_is_sorted(t_list **a);

/* Utils */

int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_substr(const char *s, int start, int len);
int		ft_min(t_list *a);
int		ft_min2(t_list *a);
void	ft_change_value(t_list *a, int min, int value);
void	ft_revalue_lst(t_list *a);
int		ft_until_nbr(t_list **a, int nbr);
void	ft_2_the_top_a(t_list **a, int n);
void	ft_2_the_top_b(t_list **b, int n);
int		ft_max(t_list *b);
int		ft_chunk_div(t_list **a, int n);
int		ft_abs(int n);

/* lstUtils */

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);

/* Order small */

void	ft_order_3(t_list **a);
void	ft_order_5(t_list **a, t_list **b);
void	ft_order_10(t_list **a, t_list **b);

/* Order big */

int		*ft_pass_2_array(t_list *a, int size);
int		ft_find_hold_top(int *ar, int inf, int sup, int size);
int		ft_find_hold_bot(int *ar, int inf, int sup, int size);
int		ft_top_or_bot(t_list **a, int hold_top, int hold_bot);
void	ft_search_chunk(t_list **a, t_list **b, int inf, int sup);
void	ft_fill_b(t_list **a, t_list **b, int size);
void	ft_order_big(t_list **a, t_list **b);

/* Push swap */

void	ft_add_nbr(char *s, t_list **a);
void	ft_pile_up(int argc, char **argv, t_list **a);
void	ft_sort_pile(t_list **a, t_list **b);
void	ft_print_lst(t_list *a);

#endif
