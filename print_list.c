/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:29:33 by afantune          #+#    #+#             */
/*   Updated: 2024/12/20 12:46:14 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d (%d) -> ", list->value, list->index);
		list = list->next;
	}
	printf("NULL\n");
}
