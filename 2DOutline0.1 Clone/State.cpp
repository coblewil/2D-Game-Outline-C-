#include "State.h"
#include "Handler.h"

State::State(const std::shared_ptr<Handler>& handler):
	handler{handler}
{
}

State::~State()
{
}
