/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:01 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/30 12:38:46 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(stack *stack)
{
	node	*temp;

	temp = stack -> top;
	while (temp -> next != NULL)
	{
		if (temp -> data > temp -> next -> data)
			return 0;
		temp = temp -> next;
	}
	return 1;
}
