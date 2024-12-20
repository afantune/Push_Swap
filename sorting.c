/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:27:41 by afantune          #+#    #+#             */
/*   Updated: 2024/12/20 13:23:03 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack != NULL)
	{
		if (stack->value < min->value)
		{
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

int	count_elements(t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i ++;
		stack = stack->next;
	}
	return (i);
}

static int	is_highest(long index, t_list *numbers)
{
	return ((numbers->index < index)
		+ (numbers->next->index < index)
		+ (numbers->next->next->index < index) >= 2);
}

void	three_sort(t_list **stack_a)
{
	//printf("inside three_sort\n");
	if (is_highest((*stack_a)->index, (*stack_a)))
	{
		ra(stack_a);
		
	}
	else if (is_highest((*stack_a)->next->index, (*stack_a)))
		{
			rra(stack_a);
			
		}
	if ((*stack_a)->index > (*stack_a)->next->index)
		{
			sa(stack_a);
			
		}
}

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		//printf("running inside while: max %d bits: %d\n", max, max_bits);
		if (head->index >= max)
		{
			//printf("got new max: old %d", max);
			max = head->index;
			//printf("new %d\n", max);
		}
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	//printf("starting radix\n");
	i = 0;
	head_a = *stack_a;
	//printf("getting size\n");
	size = ft_lstsize(head_a);
	//printf("getting max bits\n");
	max_bits = get_max_bits(stack_a);
	//printf("max bits: %d\n", max_bits);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
