/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:43:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 14:38:01 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	append_node(t_stack *stack, int nb)
{
	t_node	*node;
	t_node	*last_node;
	t_node	*current;
	
	current = stack -> top;
	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node -> next = NULL;
	node -> data = nb;
	if (!(current))
	{
		current = node;
		node -> prev = NULL;
	}
	else
	{
		last_node = get_last_node(stack);
		last_node -> next = node;
		node -> prev = last_node;
	}
}


t_node	*get_cheapest(t_stack *stack)
{
	t_node	*current;

	current = stack -> top;
	if (!stack)
		return(NULL);
	while (current)
	{
		if (current -> cheapest)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

void	push_preparation(t_stack *stack, char stack_name)
{
	t_node	*current;
	t_node	*cheap;

	if (!stack || !stack -> top)
		return ;
	current = stack -> top;
	cheap = get_cheapest(stack);
	if (!cheap)
		return ;
	while (current != cheap)
	{
		if (stack_name == 'a')
		{
			if (cheap -> data  < stack_size(stack) / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (cheap -> data < stack_size(stack) / 2)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
