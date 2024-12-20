/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:12:46 by afantune          #+#    #+#             */
/*   Updated: 2024/12/20 13:23:17 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(int value, t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value < value)
			index++;
		stack = stack->next;
	}
	return (index);
}

void	index_stack(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head)
	{
		head->index = get_index(head->value, stack);
		//printf("head->index = %d\n", head->index);
		head = head->next;
	}
}

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
