/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:27:24 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/21 20:07:28 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	int			content;
	struct list	*next;
}	t_stack;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
t_stack	*put_value(char **av, int i);
void	ft_error(int f);
t_stack	*swap_a(t_stack *x, int n);
t_stack	*rotate_a(t_stack *x, int n);
void	check(char **av);
void	push_a(t_stack **a, t_stack **b, int n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*reverse_rotate_a(t_stack *x, int n);
int		ft_lstsize(t_stack*lst);
int		top_num(t_stack *x);
int		min_num(t_stack *x);
int		*put_position(t_stack *x);
t_stack	*swap_b(t_stack *x, int n);
t_stack	*rotate_b(t_stack *x, int n);
void	push_b(t_stack **b, t_stack **a, int n);
t_stack	*reverse_rotate_b(t_stack *x, int n);
void	algorhitme(t_stack **a, t_stack **b, int *pos, int np);
t_stack	*t_stack_with_3(t_stack *a);
void	send_t_stack_b(t_stack **x, t_stack **y);
int		check_index(t_stack *b, int n);
int		check_pos(t_stack *b, int n);
void	put_elem(t_stack **b, int k, int j, int n);
void	edit_b(t_stack **a, t_stack **b, int n);
void	send_a(t_stack **x, t_stack **y, int j);
void	algo_2(t_stack **x, t_stack **y);
int		test_1(int n, int *d, int j);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ss(t_stack **k, t_stack **p, int n);
void	rrr(t_stack **k, t_stack **p, int n);
void	rr(t_stack **k, t_stack **p, int n);
void	clean_stack(t_stack **x, t_stack **y, int *pos, char **args);
void	clean_stack_a(t_stack **x);
int		check_space(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	f1_free(char **str, int i);
int		check_num(char *s);
int		check_value(char **av, char *s, int index);
char	**join_element(int ac, char **av);

#endif
