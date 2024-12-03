/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:27:30 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 21:19:53 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	int	sorted = 0;
	int swap;

	if (!lst || !cmp)
		return (NULL);
	while (sorted == 0)
	{
		sorted = 1;
		cur = lst;
		while (cur->next != NULL)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap = cur->data;
				cur->data = cur->next->data;
				cur->next->data = swap;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
	return (lst);
}

/*
int	ft_ascending(int a, int b)
{
	return (a <= b);
}

void	ft_list_put_back(t_list **head, int data)
{
	t_list	*curr;
	t_list	*new = malloc(sizeof(t_list));

	if (!new)
		return;
	new->next = NULL;
	new->data = data;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

#include <stdio.h>

void	ft_list_print(t_list *head)
{
	while (head != NULL)
	{
		printf("%i ,", head->data);
		head = head->next;
	}
	printf("\n");
}

void	ft_list_clear(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(void)
{
	int a1 = 1235, a2 = 385, a3 = 4, a4 = 50, a5 = 19, a6 = 870;
	t_list *list = NULL;

	ft_list_put_back(&list, a1);
	ft_list_put_back(&list, a2);
	ft_list_put_back(&list, a3);
	ft_list_put_back(&list, a4);
	ft_list_put_back(&list, a5);
	ft_list_put_back(&list, a6);

	printf("List: ");
	ft_list_print(list);

	list = sort_list(list, ft_ascending);
	printf("Sorted list: ");
	ft_list_print(list);
	
	ft_list_clear(list);
}
*/
