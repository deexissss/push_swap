/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:13:32 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/30 13:38:41 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(stack *stack)
{
	int	i;
	node	*temp;

	i = 0;
	temp = stack -> top;
	while (temp != NULL)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
}

node *get_last_node(stack *stack)
{
	node	*last = stack -> top;
	while (last != NULL && last -> next != NULL)
		last = last -> next;
	return last;
}
