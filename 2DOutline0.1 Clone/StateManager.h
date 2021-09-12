#pragma once
#include "State.h"
#include <memory>
class StateManager
{
private:
	//Private Variables
	static std::shared_ptr<State> currentState;
public:
	//Public Functions
	static void setState(State* state);
	static void setState(std::shared_ptr<State> state);
	static std::shared_ptr<State> getState();
};

