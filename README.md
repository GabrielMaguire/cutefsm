# cutefsm

A simple and flexible finite state machine (FSM) implementation for embedded applications.

The source files provide three finite state machine implementation options which are explained in more detail below. Each implementation uses an array of transition structures which are checked each execution cycle to see if the conditions for a transition have been met...

```c
struct Transition
{
	in_state;  /* Compared with current state                       */
	out_state; /* New current state if `condition() == true`        */
	condition; /* State transition condition                        */
	action;    /* Function to call on state transition (Mealy-only) */
}
```

...and a top-level FSM structure to bundle the transitions and keep track of the current state.
```c
struct Fsm
{
	current_state;            /* The current FSM state           */
	Transition transitions[]; /* A list of FSM state transitions */
}
```

## Moore FSM

A user-defined function is called for the current state each execution cycle. The previous state has no impact on the current function call, only the current state matters. State are implemented as functions (serves as a unique identifier for state comparisons).

## Mealy FSM

A user-defined function is called only on state transitions. The function call is determined by both the previous state and the current state. States are implemented as unique integers (uint, enum, macro).

## Hybrid (Moore + Mealy) FSM

User-defines functions are called for both the current state and any potential state transitions. This is a simple combination of the Moore and Mealy FSM structures.

## Dependencies

- `cmake` >= 3.22.1

## Building with cmake

```bash
mkdir build && cd build
cmake .. # Use `cmake -DBUILD_HYBRID=ON ..` to build FSM library as state-is-function variant 
cmake --build . # Build all targets (library and examples)
./examples/fsm-state-is-function/ExampleHybridFSM # Run example executable
```