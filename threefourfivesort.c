/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threefourfivesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:27:44 by afantune          #+#    #+#             */
/*   Updated: 2025/01/08 13:38:25 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_highest(long index, t_list *numbers)
{
	return ((numbers->index < index)
		+ (numbers->next->index < index)
		+ (numbers->next->next->index < index) >= 2);
}

void	three_sort(t_list **stack_a)
{
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

void	real_four_five_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a[0]) == 5)
		pb(stack_a, stack_b);
	(pb(stack_a, stack_b), three_sort(stack_a));
	while (stack_b[0])
	{
		if (stack_b[0]->value < stack_a[0]->value)
			pa(stack_a, stack_b);
		else if (stack_b[0]->value < stack_a[0]->next->value)
			(ra(stack_a), pa(stack_a, stack_b), rra(stack_a));
		else if (stack_b[0]->value < stack_a[0]->next->next->value)
		{
			if (ft_lstsize(stack_a[0]) == 4)
				rra(stack_a);
			(rra(stack_a), pa(stack_a, stack_b), ra(stack_a), ra(stack_a));
			if (ft_lstsize(stack_a[0]) == 5)
				ra(stack_a);
		}
		else if (ft_lstsize(stack_a[0]) == 4
			&& stack_b[0]->value < stack_a[0]->next->next->next->value)
			(rra(stack_a), pa(stack_a, stack_b), ra(stack_a), ra(stack_a));
		else
			(pa(stack_a, stack_b), ra(stack_a));
	}
}

void	specific_cases(t_list **a, t_list **b)
{
	int	fourth;
	int	fifth;

	fourth = a[0]->next->next->next->value;
	fifth = a[0]->next->next->next->next->value;
	if (a[0]->index != 2
		|| (a[0]->next->index != 3 && a[0]->next->index != 1))
		return ;
	if (a[0]->next->next->value == 2 && fourth == 1 && fifth == 5)
		(pb(a, b), pb(a, b), sa(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->value == 5 && fourth == 1 && fifth == 2)
		(ra(a), ra(a), ra(a));
	if (a[0]->next->next->value == 1 && fourth == 5 && fifth == 2)
		(ra(a), ra(a), sa(a), ra(a));
	if (a[0]->next->next->value == 1 && fourth == 5 && fifth == 4)
		(pb(a, b), rra(a), pb(a, b), rra(a),
			pa(a, b), pa(a, b), rra(a), rra(a), sa(a));
	if (a[0]->next->next->value == 5 && fourth == 2 && fifth == 1)
		(rra(a), rra(a), sa(a));
	if (a[0]->next->next->value == 2 && fourth == 5 && fifth == 1)
		(pb(a, b), pb(a, b), rra(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->value == 5 && fourth == 4 && fifth == 1)
		(sa(a), rra(a), rra(a), rra(a), sa(a), ra(a), ra(a));
}

void	four_five_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a[0]) == 5)
		specific_cases(stack_a, stack_b);
	if (!is_sorted(&stack_a[0]))
		real_four_five_sort(stack_a, stack_b);
}
