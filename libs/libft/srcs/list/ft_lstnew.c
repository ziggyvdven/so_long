/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:55:05 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/21 13:39:25 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_node	*ft_lstnew(int content)
{
	t_node	*next;

	next = (t_node *)malloc(sizeof(t_node));
	if (!(next))
		return (NULL);
	next->n = content;
	next->next = NULL;
	return (next);
}

// int main(void)
// {
//     char *str = "hello world";
//     t_list *node = ft_lstnew(str);
//     if (node == NULL)
//     {
//         printf("Error: failed to create new node\n");
//         return (1);
//     }
//     printf("Node content: %s\n", (char *)node->content);
//     return (0);
// }
