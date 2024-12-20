/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:32:33 by afantune          #+#    #+#             */
/*   Updated: 2024/12/18 15:05:43 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

int main()
{
    // Create a new list node with an integer value
    int value = 42;
    t_list *node = ft_lstnew(&value); // Pass the address of the integer

    // Check if the node was created successfully
    if (node == NULL) {
        printf("Failed to create node.\n");
        return 1; // Exit if allocation failed
    }

    // Output the content of the node
    printf("Node content: %d\n", *(int*)node->content); 
	// Dereference to get the value
    printf("Next node: %p\n", node->next); // Should be NULL

    // Free the allocated node
    free(node);

    return 0;
}*/
