#include "fsm.h"

void callFsm(struct Fsm *fsm, size_t trans_size)
{
	if (!fsm) { return; }

	size_t i;
	for (i = 0; i < trans_size; ++i)
	{
		if (fsm->current_state == fsm->transitions[i].in_state &&
			fsm->transitions[i].entry_condition())
		{
			fsm->current_state = fsm->transitions[i].out_state;
		}
		fsm->current_state();
	}
}