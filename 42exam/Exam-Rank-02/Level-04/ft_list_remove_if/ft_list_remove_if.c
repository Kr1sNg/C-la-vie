/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:26:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 20:08:39 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr;
	t_list *temp;

	while (*begin_list != NULL && cmp((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	curr = *begin_list;
	while (curr != NULL && curr->next != NULL)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			temp = curr->next;
			curr->next = curr->next->next;
			free(temp);
		}
		else
		{
			curr = curr->next;
		}
	}
}

/*
void	ft_list_put_front(t_list **head, void *data)
{
	t_list	*new = malloc(sizeof(t_list));

	if (!new)
		return ;
	new->data = data;
	new->next = *head;
	*head = new;
}

int	ft_cmp_int(void *data, void *data_ref)
{
	return (*(int *)data - *(int *)data_ref);
}


#include <stdio.h>

void	ft_list_print(t_list *head)
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
	t_list	*curr;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

int	main(void)
{
	t_list	*list = NULL;
	int a1 = 19, a2 = 19, a3 = 3, a4 = 19, a5 = 19, a6 = 19;
	int x = 19;
	
	ft_list_put_front(&list, &a1);
	ft_list_put_front(&list, &a2);
	ft_list_put_front(&list, &a3);
	ft_list_put_front(&list, &a4);
	ft_list_put_front(&list, &a5);
	ft_list_put_front(&list, &a6);

	printf("List: ");
	ft_list_print(list);

	ft_list_remove_if(&list, &x, ft_cmp_int);
	printf("New list: ");
	ft_list_print(list);

	ft_list_clear(list);
}
*/
