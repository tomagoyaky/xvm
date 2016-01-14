#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "stack.h"
#include "types.h"

bool init_stack(stack *s, unsigned int max_size)
{
	s->max_size = max_size;
	s->curr_size = 0;
	s->data = (xvm_int*) calloc(max_size, sizeof(xvm_int));
	if (!s->data) return false;
	else return true;
}

bool is_empty(stack *s)
{
	return (s->curr_size == 0);
}

bool is_full(stack *s)
{
	return (s->curr_size >= s->max_size);
}

bool push(stack *s, xvm_int val)
{
	if is_full(s) return false;
	s->data[curr_size] = val;
	curr_size++;
	return true;
}

bool pop(stack *s)
{
	if is_empty(s) return false;
	curr_size--;
	return true;
}

xvm_int top(stack*s)
{
	if is_empty(s) return INT64_MIN;
	xvm_int top_val = s->data[curr_size];
	curr_size--;
	return top_val;
}

bool pop_all(stack *s)
{
	if is_empty(s) return false;
	while (!is_empty(s))
		pop(s);
	return true;
}