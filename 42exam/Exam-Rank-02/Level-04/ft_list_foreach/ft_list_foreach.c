/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:32:11 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 20:21:47 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_foreach(t_list	*begin_list, void (*f)(void *))
{
	t_list	*curr;

	if (!begin_list || !f)
		return ;
	curr = begin_list;
	while (curr != NULL)
	{
		(*f)(curr->data);
		curr = curr->next;
	}
}

/*
void	ft_list_add_front(t_list **head, void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = data;
	new->next = *head;
	*head = new;
}

void	ft_double(void *data)
{
	*(int *)data = (*(int *)data) * 2;
}

#include <stdio.h>
	
void	ft_list_printf(t_list *head)
{
	while (head != NULL)
	{
		printf("%i, ", *(int *)head->data);
		head = head->next;
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
	t_list	*list = NULL;
	int a1 = 1, a2 = 2, a3 = 3, a4 = 5, a5 = 11;
	ft_list_add_front(&list, &a1);
    ft_list_add_front(&list, &a2);
    ft_list_add_front(&list, &a3);
    ft_list_add_front(&list, &a4);
    ft_list_add_front(&list, &a5);

	printf("list: ");
	ft_list_printf(list);
	
	printf("New list: ");
	ft_list_foreach(list, ft_double);
	ft_list_printf(list);

	ft_list_clear(list);
}
*/
