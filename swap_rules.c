/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:53:44 by afantune          #+#    #+#             */
/*   Updated: 2025/01/14 12:36:20 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	int	temp_value;
	int	temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	if ((*stack) == NULL || (*stack)->next == NULL)
		ft_error("Error occurred while swapping!");
	temp_value = (*stack)->value;
	temp_index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = temp_value;
	(*stack)->next->index = temp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
