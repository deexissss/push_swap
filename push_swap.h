/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:09 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 13:00:17 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "z_printf/ft_printf.h"
# include "z_libft/libft.h"

typedef struct node
{
	int			index;
	int			data;
	int			push_cost;
	bool		above_median;
	bool		cheapest;
	struct node	*next;
	struct node	*prev;
	struct node	*target;
}	t_node;

typedef struct stack
{
	t_node	*top;
}	t_stack;

/*OPERATIONS*/
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stacka, t_stack *stackb);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stacka, t_stack *stackb);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stacka, t_stack *stackb);
void	pa(t_stack *stacka, t_stack *stackb);
void	pb(t_stack *stacka, t_stack *stackb);
void	both_reverse_rotate(t_stack *stack1, t_stack *stack2, t_node *cheapest);
void	both_rotate(t_stack *stack1, t_stack *stack2, t_node *cheapest);

/*STACK UTILS*/

t_node	*create_new_node(int data);
t_node	*get_last_node(t_stack *stack);
t_node	*get_cheapest(t_stack *stack);
void	init_stack(t_stack *stack);
void	init_stack_a(t_stack *stacka, char **argv);
void	add_node(t_stack *stack, int data);
void	move_node(t_stack *stack1, t_stack *stack2);
void	display_stack(t_stack *stack);
int		ft_checksorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		ft_stacklast(t_stack *stack);
int		is_empty(t_stack *stack);
int		ft_remove(t_stack *stack);

/*CHECK UTILS*/

int		syntax_error(char *str);
int		duplicate_nb(t_stack *stack, int nb);
int		only_digit(const char *str);
char	**split_nb(const char *str, char c);
void	free_stack(t_stack *stack);
void	error(t_stack *stack);

/*SORT*/

void	sort_three(t_stack *stack);
void	stack_division(t_stack *stack1, t_stack *stack2);
void	current_index(t_stack *stack);
void	init_nodes_1(t_stack *stack1, t_stack *stack2);
void	init_nodes_2(t_stack *stack1, t_stack *stack2);
void	push_preparation(t_stack *stack, char stack_name);
void	set_cheapest_nb(t_stack *stack);
void	min_to_top(t_stack *stack1);
void	move_a_to_b(t_stack *stack1, t_stack *stack2);
void	move_b_to_a(t_stack *stack1, t_stack *stack2);
void	sort_stacks(t_stack *stack1, t_stack *stack2);

#endif
