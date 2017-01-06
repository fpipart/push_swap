
#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
}

int		rra(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	return (1);
}

int		rrb(t_stack **a, t_stack **b)
{
	reverse_rotate(b);
	return (1);
}

int		rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (1);
}
