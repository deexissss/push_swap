/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:09 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 14:16:35 by tjehaes          ###   ########.fr       */
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

typedef struct	node
{
	int	index;
	int	data;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct node	*next;
	struct node	*prev;
	struct node	*target;
}	node;

typedef struct	stack
{
	node*	top;
}	stack;

node	*create_new_node(int data);
void	init_stack(stack *stack);
int	is_empty(stack *stack);
void	add_node(stack *stack, int data);
int	remove(stack *stack);
void	move_node(stack *stack1, stack *stack2);
void	display_stack(stack *stack);
void	sa(stack *stack);
void	sb(stack *stack);
void	ss(stack *stacka, stack *stackb);
void	ra(stack *stack);
void	rb(stack *stack);
void	rr(stack *stacka, stack *stackb);
void	rra(stack *stack);
void	rrb(stack *stack);
void	rrr(stack *stacka, stack *stackb);
void	pa(stack *stacka, stack *stackb);
void	pb(stack *stacka, stack *stackb);
int	ft_checksorted(stack *stack);
int	stack_size(stack *stack);
void	sort_three(stack *stack);
void	stack_division(stack *stack1, stack *stack2);
node *get_last_node(stack *stack);
void    add_node_end(stack *stack, int data);
int     find_max(stack *stack);
int	find_min(stack *stack);
void	current_index(stack *stack);
void	init_nodes_1(stack *stack1, stack *stack2);

#endif

