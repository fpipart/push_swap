
void push(t_stack **stack1, t_stack **stack2)
{
	int tmp;

	if (stack && (*stack)->next &&	 (*stack) != (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data =  tmp;
	}
}

