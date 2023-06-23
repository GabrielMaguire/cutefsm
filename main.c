#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "fsm.h"

bool transition_one_to_two(void) { return true; }
bool transition_two_to_three(void) { return true; }
bool transition_three_to_one(void) { return true; }

void state_one(void) { printf("State 1\n"); }
void state_two(void) { printf("State 2\n"); }
void state_three(void) { printf("State 3\n"); }

#define TRANS_SIZE 3U
struct Fsm fsm = {
	.current_state = state_one,
	.transitions = {
		{state_one, transition_one_to_two, state_two},
		{state_two, transition_two_to_three, state_three},
		{state_three, transition_three_to_one, state_one}
	}
};

int main(int argc, char** argv)
{
	while (true)
	{
		callFsm(&fsm, TRANS_SIZE);
	}

	return 0;
}