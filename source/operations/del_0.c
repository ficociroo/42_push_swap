#include "../../includes/push_swap.h"

void	print_stacks(t_stacks *stacks)
{
		int		i;

	i = 0;
	printf(" A(%d) --- B(%d) \n", stacks->qty[0], stacks->qty[1]);
	while (i <= stacks->qty[0] || i <= stacks->qty[1])
	{
		if (i > stacks->qty[0])
			printf("  /   ---%2d/%3d\n", stacks->idx[1][i], stacks->val[1][i]);
		else if (i > stacks->qty[1])
			printf("%2d/%3d---  /   \n", stacks->idx[0][i], stacks->val[0][i]);
		else
			printf("%2d/%3d---%2d/%3d\n", stacks->idx[0][i], stacks->val[0][i], stacks->idx[1][i], stacks->val[1][i]);
		i++;
	}
}
