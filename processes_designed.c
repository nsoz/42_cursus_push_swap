#include "push_swap.h"

void	ft_processes_design(int repeat_a, int repeat_b, int	flag_for_a, int flag_for_b)
{
	int repeat;

	if ((flag_for_a == flag_for_b) && flag_for_a = 2)
	{
		if (repeat_a > repeat_b)
			repeat = repeat_b;
		else
			repeat = repeat_a;
		while(repeat--)
			ft_rev_process();
	}
}