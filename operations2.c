/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:48:06 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/21 14:56:01 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(stack *stack1, stack *stack2)
{
	ft_swap(stack1);
	ft_swap(stack2);
}

void	ft_rr(stack *stack1, stack *stack2)
{
	ft_rotate(stack1);
	ft_rotate(stack2);
}

void	ft_rrr(stack *stack1, stack *stack2)
{
	ft_reverse_rotate(stack1);
	ft_reverse_rotate(stack2);
}
