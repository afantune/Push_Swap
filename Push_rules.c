/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:44:59 by afantune          #+#    #+#             */
/*   Updated: 2025/01/14 12:33:57 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;

	if (!(*stack_from))
		return (-1);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_to == NULL)
	{
		*stack_to = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
