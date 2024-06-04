/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:25 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 14:55:38 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklast(stack *stack)
{
	if (stack -> top == NULL)
		return 0;
	node *current = stack -> top;
	while (current -> next != NULL)
		current = current -> next;
	return current -> data;
}

int	main(int argc, char **argv)
{
	stack	*stack_a;
	stack	*stack_b;
	int		i;
	int		nb;

	stack_a = malloc(sizeof(stack));
	stack_b = malloc(sizeof(stack));
	if (!stack_a || !stack_b)
		return (1);
	init_stack(stack_a);
	init_stack(stack_b);
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			nb = ft_atoi(argv[i]);
			add_node_end(stack_a, nb);
			i++;
		}
		ft_printf("before modification\n");
		display_stack(stack_a);
		ft_printf("the max in the list is %i", find_max(stack_a));
		ft_printf("the min i the list is %i", find_min(stack_a));
		ft_printf("\napres tri\n stack a \n");
		display_stack(stack_a);
		//ft_printf("apres tri\n stack b \n");
                //display_stack(stack_b);

	}
	while (!is_empty(stack_a))
		remove(stack_a);
	while (!is_empty(stack_b))
		remove(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
