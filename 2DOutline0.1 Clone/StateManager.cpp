#include "StateManager.h"
#include "State.h"
#include <memory>

std::shared_ptr<State> StateManager::currentState{nullptr};

void StateManager::setState(State* state)
{
	currentState = std::shared_ptr<State>(state);
}

void StateManager::setState(std::shared_ptr<State> state)
{
	currentState = state;
}

std::shared_ptr<State> StateManager::getState()
{
	return currentState;
}
