#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "fsm.h"

void state_a(void) { printf("State A\n"); }
void state_b(void) { printf("State B\n"); }
void state_c(void) { printf("State C\n"); }

bool condition_a_to_b(void) { return true; }
bool condition_b_to_c(void) { return true; }
bool condition_c_to_a(void) { return true; }

void action_a_to_b(void) { printf("A -> B\n"); }
void action_b_to_c(void) { printf("B -> C\n"); }
void action_c_to_a(void) { printf("C -> A\n"); }

#define NUM_TRANSITIONS 3U
struct Fsm fsm = {
	.current_state = state_a,
	.transitions = {
		{state_a, state_b, condition_a_to_b, action_a_to_b},
		{state_b, state_c, condition_b_to_c, action_b_to_c},
		{state_c, state_a, condition_c_to_a, action_c_to_a}
	}
};

int main(int argc, char** argv)
{
	while (true)
	{
		callFsm(&fsm, NUM_TRANSITIONS);
		sleep(1);
	}

	return 0;
}
