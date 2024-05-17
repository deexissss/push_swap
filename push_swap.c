/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:25 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/17 16:18:02 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(stack *stack)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = stack -> top -> data;
	nb2 = stack -> top -> next -> data;
	nb3 = stack -> top -> next -> next -> data;
	if (is_empty(stack) || stack -> top -> next == NULL || stack -> top -> next -> next == NULL)
		return;
	if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3) //3_1_2
		ft_rotate(stack);
	else if (nb1 > nb2 && nb2 > nb3 && nb1 > nb3) //3_2_1
	{
		ft_swap(stack);
		ft_reverse_rotate(stack);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3) //2_3_1
		ft_reverse_rotate(stack);
	else if (nb1 > nb2 && nb2 < nb3 && nb1 < nb3) //2_1_3
		ft_swap(stack);
	else if (nb1 < nb2 && nb2 > nb3 && nb1 < nb3) //1_3_2
	{
		ft_swap(stack);
		ft_rotate(stack);
	}
}

void	sort_five(stack *stack1, stack *stack2)
{
	if (is_empty(stack1))
		return;
	ft_push(stack1, stack2);
	ft_push(stack1, stack2);
	sort_three(stack1);
	while (!is_empty(stack2))
	{
		int val = remove(stack2);
		if (val < stack1->top->data)
		{
			add_node(stack1, val);
		}
		else
		{
			int temp1 = remove(stack1);
			if (is_empty(stack1) || val < stack1->top->data)
			{
				add_node(stack1, val);
				add_node(stack1, temp1);
			}
			else
			{
				int temp2 = remove(stack1);
				if (is_empty(stack1) || val < stack1->top->data)
				{
					add_node(stack1, val);
					add_node(stack1, temp2);
					add_node(stack1, temp1);
				}
				else
				{
					add_node(stack1, val);
					add_node(stack1, temp2);
					add_node(stack1, temp1);
				}
			}
		}
	}
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
			add_node(stack_a, nb);
			i++;
		}
		ft_printf("before modification\n");
		display_stack(stack_a);
		sort_three(stack_a);
		ft_printf("apres tri\n");
		display_stack(stack_a);
	}
	while (!is_empty(stack_a))
		remove(stack_a);
	while (!is_empty(stack_b))
		remove(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
