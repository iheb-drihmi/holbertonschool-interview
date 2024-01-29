#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - check if the sandpile is stable
 * @grid: sandpile to check
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - topple the sandpile
 * @grid: sandpile to topple
 */
void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3];

	add_grids(grid, tmp);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (tmp[i][j] > 3)
			{
				grid[i][j] -= 4;

				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
			}
	}
}

/**
 * add_grids - add two grids
 * @grid1: first grid
 * @grid2: second grid
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}
