#include "fsm.h"

void callFsm(struct Fsm *fsm, size_t num_transitions)
{
	if (!fsm) { return; }

	/* Transition state */
	size_t i;
	for (i = 0UL; i < num_transitions; ++i)
	{
		if (fsm->current_state == fsm->transitions[i].in_state &&
		    fsm->transitions[i].condition())
		{
#ifdef BUILD_MEALY
			/* Call optional transition action */
			if (fsm->transitions[i].action)
			{
				fsm->transitions[i].action();
			}
#endif

			fsm->current_state = fsm->transitions[i].out_state;
			break;
		}
	}

#ifdef BUILD_MOORE
	/* Execute state */
	fsm->current_state();
#endif

}
