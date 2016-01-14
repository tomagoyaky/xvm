#ifndef STACK_H_
#define STACK_H_

#include "types.h"

typedef struct stack{
	unsigned int max_size;
	unsigned int curr_size;
	xvm_int *data;
} stack;

bool init_stack(stack *s, unsigned int max_size);
bool is_empty(stack *s);
bool is_full(stack *s);
bool push(stack *s, xvm_int val);
bool pop(stack *s);
xvm_int top(stack *s);
bool pop_all(stack *s);

#endif