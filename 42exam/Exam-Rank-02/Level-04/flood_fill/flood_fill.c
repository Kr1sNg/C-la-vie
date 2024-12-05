/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:48:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tab[y][x] because in the tabs it goes with y lines and x column;

#include "flood_fill.h"

void	ft_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
		return ;
	if (tab[cur.y][cur.x] != to_fill || tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';

	ft_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	ft_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	ft_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	ft_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	ft_fill(tab, size, begin, tab[begin.y][begin.x]);
}

/*
char** make_area(char** zone, t_point size)
{
    char** new;

    new = malloc(sizeof(char*) * size.y);
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];
        new[i][size.x] = '\0';
    }

    return new;
}

int main(void)
{
    t_point size = {8, 5};
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
    };

    char**  area = make_area(zone, size);
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
    printf("\n");

    t_point begin = {5, 1};
    flood_fill(area, size, begin);
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
	for (int i = 0; i < size.y; ++i)
		free(area[i]);
	free(area);
    return (0);
}
*/
