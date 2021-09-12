#include "ClickListener.h"

ClickListener::ClickListener(std::function<void()> func):
	onClick{func}
{
}
