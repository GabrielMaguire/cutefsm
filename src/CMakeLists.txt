add_library(FSM STATIC fsm.c)

option(BUILD_MOORE "Compile as a Moore FSM (state-centric)" OFF)
option(BUILD_MEALY "Compile as a Mealy FSM (transition-centric)" OFF)

if(BUILD_MOORE AND BUILD_MEALY)
	target_compile_definitions(FSM PRIVATE BUILD_MOORE BUILD_MEALY)
elseif(BUILD_MEALY)
	target_compile_definitions(FSM PRIVATE BUILD_MEALY)
else()
	target_compile_definitions(FSM PRIVATE BUILD_MOORE)
endif()

set_target_properties(FSM PROPERTIES C_STANDARD 99)
