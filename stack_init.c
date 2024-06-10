/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:43:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 10:08:12 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_str_to_long(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack -> top)
		return (NULL);
	current = stack -> top;
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
			if (cheap -> index < stack_size(stack) / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (cheap -> index < stack_size(stack) / 2)
				rb(stack);
			else
				rrb(stack);
		}
		current = current -> next;
	}
}

void	init_stack_a(t_stack *stacka, char **argv)
{
	t_node	*current;
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error(stacka);
		n = ft_str_to_long(argv[1]);
		if (n > INT_MAX || n < INT_MIN)
			error(stacka);
		if (duplicate_nb(stacka, (int)n))
			error(stacka);
		add_node(stacka, (int)n);
		i++;
	}
}
