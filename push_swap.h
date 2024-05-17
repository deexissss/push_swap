/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:09 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/17 14:57:11 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct	node
{
	int	data;
	struct node*	next;
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
void	ft_swap(stack *stack);
void	ft_rotate(stack *stack);
void	ft_reverse_rotate(stack *stack);
void	ft_push(stack *stack1, stack *stack2);

#endif
