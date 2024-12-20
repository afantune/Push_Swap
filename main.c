/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:25 by afantune          #+#    #+#             */
/*   Updated: 2024/12/20 15:02:44 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	(void)argc;
/* 	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{ */
	i = 1;
	args = argv;
/* 	} */
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(*stack);
	/* if (argc == 2)
		ft_free(args); */
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		three_sort(stack_a);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argc, argv);
	/* printf("Stack A before sorting: "); */
	/* print_list(*stack_a); */
	if (!is_sorted(stack_a) && argc == 3)
		ra(stack_a);
	if (is_sorted(stack_a))
	{
		/* printf("Stack is already sorted.\n"); */
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	/* printf("Stack A after sorting: "); */
	/* print_list(*stack_a); */
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
