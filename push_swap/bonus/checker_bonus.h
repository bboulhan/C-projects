/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:59:48 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 12:55:52 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../mandatory/push_swap.h"
# include "get_next_line.h"

int		read_line_2(t_stack **x, t_stack **y, char *line);
int		read_line(t_stack **x, t_stack **y, char *line);
void	read_instructions(t_stack **x, t_stack **y);
void	calcul(t_stack *x, t_stack *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ss_bonus(t_stack **k, t_stack **p);
t_stack	*reverse_rotate_a_bonus(t_stack *x);
void	push_a_bonus(t_stack **a, t_stack **b);
t_stack	*rotate_a_bonus(t_stack *x);
t_stack	*swap_a_bonus(t_stack *x);
void	rrr_bonus(t_stack **k, t_stack **p);
void	rr_bonus(t_stack **k, t_stack **p);
t_stack	*reverse_rotate_b_bonus(t_stack *x);
void	push_b_bonus(t_stack **b, t_stack **a);
t_stack	*rotate_b_bonus(t_stack *x);
t_stack	*swap_b_bonus(t_stack *x);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	clean_stack_bonus(t_stack **x, t_stack **y);

#endif
