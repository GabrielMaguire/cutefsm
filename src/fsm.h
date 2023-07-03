#ifndef FSM_H
#define FSM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool (*bool_fn_ptr)(void);
typedef void (*void_fn_ptr)(void);

/** @brief State transition descriptor */
struct Transition
{
#ifdef BUILD_MOORE
	const void_fn_ptr in_state;
	const void_fn_ptr out_state;
#else
	const uint32_t in_state;
	const uint32_t out_state;
#endif

	const bool_fn_ptr condition;

#ifdef BUILD_MEALY
	const void_fn_ptr action;
#endif
};

/** @brief Finite state machine descriptor */
struct Fsm
{
#ifdef BUILD_MOORE
	void_fn_ptr current_state;
#else
	uint32_t current_state;
#endif
	const struct Transition transitions[];
};

/**
 * @brief Execute a finite state machine
 * 
 * @param fsm 		  Finite state machine descriptor
 * @param num_transitions Number of state transitions in `fsm::transitions`
 */
void callFsm(struct Fsm *fsm, size_t trans_size);

#endif /* FSM_H */
