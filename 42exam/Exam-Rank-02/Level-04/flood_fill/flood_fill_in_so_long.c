/* a small part of So_long when checking if a map is valid */
/*
code a function that can check if player 'P' can get access
to take all coins 'C' and can get access to the exit 'E' or not?
we know that P can't go through wall '1' and 'E', but can go
through floors '0' and go through and collect coin 'C'.

Example:
11111111
1CEP1001
11111111
=> return False

111111
1ECP11
111111
=> return True
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ft_floodfill(char **matrix, int row, int col)
{
    if (matrix[row][col] == '1')
        return;
    else if  (matrix[row][col] == 'E')
    {
        matrix[row][col] = '1';
        return;
    }
    matrix[row][col] = '1';
    ft_floodfill(matrix, row + 1, col);
    ft_floodfill(matrix, row - 1, col);
    ft_floodfill(matrix, row, col + 1);
    ft_floodfill(matrix, row, col - 1);
}

bool ft_check_access(char **matrix, int rows, int cols)
{
    int p_row = -1, p_col = -1;
    int r, c;

    // Find player 'P'
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            if (matrix[r][c] == 'P')
            {
                p_row = r;
                p_col = c;
            }
    if (p_row == -1 || p_col == -1)
        return false;

    // Flood fill from 'P'
    ft_floodfill(matrix, p_row, p_col);

    // Check if any 'C' or 'E' is still present
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            if (matrix[r][c] == 'C' || matrix[r][c] == 'E')
                return false;

    return true;
}

// Test function
void print_result(char **map, int rows, int cols)
{
    // Create a copy of the map to avoid modifying the original
    char temp_map[rows][cols + 1];
    for (int i = 0; i < rows; i++)
        strcpy(temp_map[i], map[i]);

    // Convert array of pointers to array of strings
    char *map_copy[rows];
    for (int i = 0; i < rows; i++)
        map_copy[i] = temp_map[i];

    if (ft_check_access(map_copy, rows, cols))
        printf("Player can collect all coins and reach the exit.\n");
    else
        printf("Player cannot collect all coins or reach the exit.\n");
}

int main()
{
    char *map1[] = {
        "11111111",
        "11E1CP01",
        "11111111"
    };
    char *map2[] = {
        "111111",
        "1E1P01",
        "11C001",
        "111111"
    };

    printf("Testing map 1:\n");
    print_result(map1, 3, 8);

    printf("\nTesting map 2:\n");
    print_result(map2, 4, 6);

    return 0;
}
