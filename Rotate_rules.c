/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:49:46 by afantune          #+#    #+#             */
/*   Updated: 2025/01/14 12:36:02 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack))
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) < 0)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
