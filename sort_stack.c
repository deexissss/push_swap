/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:54:57 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/07 11:33:26 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *stack1, t_stack *stack2)
{
	int	len;
	t_node	*current1;
	t_node	*current2;

	len = stack_size(stack1);
	current1 = stack1 -> top;
	if (len-- > 3 && !ft_checksorted(stack1))
		pb(stack1, stack2);
	if (len-- > 3 && !ft_checksorted(stack1))
		pb(stack1, stack2);
	while (len-- > 3 && !ft_checksorted(stack1))
	{
		init_nodes_1(stack1, stack2);
		move_a_to_b(stack1, stack2);
	}
	sort_three(stack1);
	while (stack2)
	{
		init_nodes_2(stack1, stack2);
		move_b_to_a(stack1, stack2);
	}
	current_index(stack1);
	min_to_top(stack1);
}
