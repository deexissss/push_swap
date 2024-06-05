/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:01 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 10:19:46 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack -> top;
	while (temp -> next != NULL)
	{
		if (temp -> data > temp -> next -> data)
			return (0);
		temp = temp -> next;
	}
	return (1);
}

