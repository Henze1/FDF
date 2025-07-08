/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:55:45 by hpodratc          #+#    #+#             */
/*   Updated: 2025/01/20 10:17:22 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr;
		curr = curr -> next;
		del(tmp -> content);
		free(tmp);
	}
	*lst = NULL;
}
