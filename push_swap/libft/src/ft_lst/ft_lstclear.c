/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztokluog <ztokluog@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:02:16 by ztokluog          #+#    #+#             */
/*   Updated: 2023/06/11 08:02:17 by ztokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Deletes and frees the given element and every successor of that element, 
*	using the function ’del’ and free(3). Finally, the pointer to the list must 
*	be set to NULL.
*	PARAMETERS
*	#1. The adress of a pointer to an element.
*	#2. The adress of the function used to delete the content of the element.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;

	if (*lst)
	{
		while (*lst)
		{
			aux_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux_lst;
		}
		*lst = 0;
	}
}
