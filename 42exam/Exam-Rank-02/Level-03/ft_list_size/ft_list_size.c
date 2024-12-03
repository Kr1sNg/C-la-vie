/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:41:59 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 20:19:37 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	t_list	*cur = begin_list;
	int		i = 0;

	while (cur != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new = malloc(sizeof(t_list));

	if (!new)
		return (NULL);
	new->next = NULL;
	new->data = data;
	return (new);
}

void	ft_list_add_front(t_list **head, void *data)
{
	t_list *new = ft_create_elem(data);

	if (!new)
		return ;
	new->next = *head;
	*head = new;
}

void	ft_print_list(t_list *head)
{
	t_list *curr = head;
	
	while (curr != NULL)
	{
		printf("%i, ", *(int *)curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void	ft_list_clear(t_list *head)
{
	t_list *temp;

	while (head != NULL)
	{
		temp = head;	
		head = head->next;
		free(temp);
	}
}

int	main(void)
{
	int a1 = 1, a2 = 2, a3 = 3, a4 = 4, x = 7;

	t_list *list = NULL;

	ft_list_add_front(&list, &a1);
	ft_list_add_front(&list, &a2);
	ft_list_add_front(&list, &a3);
	ft_list_add_front(&list, &a4);
	ft_list_add_front(&list, &x);

	printf("List: ");
	ft_print_list(list);

	int len = ft_list_size(list);
	printf("len: %i", len);

	ft_list_clear(list);
}
*/	
