/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:56:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/03 10:46:36 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_division(stack *stack1, stack *stack2)
{
	stack	*temp;
	int	min;
	int	max;
	node	*min_n;
	node	*max_n;

	min = 0;
	max = 0;
	ft_push(stack1, stack2);
	ft_push(stack1, stack2);
	if (stack2 -> top -> data < stack2 -> top -> next -> data)
	{
		ft_swap(stack2);
	}
	max = stack2 -> top -> data;
	min = stack2 -> top -> next -> data;
	while (stack_size(stack1) > 3 && !ft_checksorted(stack1))
	/*{
		min_n = get_last_node(stack2);
		min = min_n -> data;
		max_n = stack2 -> top;
		max = max_n -> data;
		if (stack1 -> top -> data < min)
		{
			ft_push(stack1, stack2);
			ft_rotate(stack2);
		}
		else if (stack1 -> top -> data > max)
			ft_push(stack1, stack2);
		else if (stack1 -> top -> data > min && stack1 -> top -> data < max)
		{
			ft_push(stack1, stack2);
			ft_swap(stack2);
		}
	}*/
	{
		min_n = stack1 -> top;
		max_n = stack2 -> top;
		while (min_n > max_n)
			max_n = max_n -> next;
		ft_push(stack1, stack2);
	}
	sort_three(stack1);
	while (stack_size(stack2) > 0)
		ft_push(stack2, stack1);

}
