#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "fsm.h"

enum State
{
	A,
	B,
	C
};

bool condition_a_to_b(void) { return true; }
bool condition_b_to_c(void) { return true; }
bool condition_c_to_a(void) { return true; }

void action_a_to_b(void) { printf("A -> B\n"); }
void action_b_to_c(void) { printf("B -> C\n"); }
void action_c_to_a(void) { printf("C -> A\n"); }

#define NUM_TRANSITIONS 3U
struct Fsm fsm = {
	.current_state = A,
	.transitions = {
		{A, B, condition_a_to_b, action_a_to_b},
		{B, C, condition_b_to_c, action_b_to_c},
		{C, A, condition_c_to_a, action_c_to_a}
	}
};

int main(int argc, char** argv)
{
	while (true)
	{
		callFsm(&fsm, NUM_TRANSITIONS);
		sleep(1U);
	}

	return 0;
}
