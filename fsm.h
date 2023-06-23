#ifndef FSM_H
#define FSM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool (*bool_fn_ptr)(void);
typedef void (*void_fn_ptr)(void);

struct Transition
{
	const void_fn_ptr in_state;
	const bool_fn_ptr entry_condition;
	const void_fn_ptr out_state;
};

struct Fsm
{
	void_fn_ptr current_state;
	struct Transition transitions[];
};

void callFsm(struct Fsm *fsm, size_t trans_size);

#endif /* FSM_H */