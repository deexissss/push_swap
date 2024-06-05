/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:33:27 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 09:45:45 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack1, t_stack *stack2)
{
	int	data;

	data = ft_remove(stack1);
	if (data != -1)
		add_node(stack2, data);
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	ft_push(stackb, stacka);
	ft_printf("pa\n");
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	ft_push(stacka, stackb);
	ft_printf("pb\n");
}
