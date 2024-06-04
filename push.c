/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:33:27 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 11:52:29 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(stack *stack1, stack *stack2)
{
	int	data;

	data = remove(stack1);
	if (data != -1)
		add_node(stack2, data);
}

void	pa(stack *stacka, stack *stackb)
{
	ft_push(stackb, stacka);
	ft_printf("pa\n");
}

void	pb(stack *stacka, stack *stackb)
{
	ft_push(stacka, stackb);
	ft_printf("pb\n");
}
