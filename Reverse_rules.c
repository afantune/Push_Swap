/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:10:29 by afantune          #+#    #+#             */
/*   Updated: 2024/12/20 12:06:04 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack))
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	while (head->next != tail)
	{
		head = head->next;
	}
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) < 0)
		return (-1);
	printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) < 0)
		return (-1);
	printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
	return (0);
}
