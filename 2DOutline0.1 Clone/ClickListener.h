#pragma once
#include <functional>
#include <utility>
class ClickListener
{
private:
public:
	ClickListener(std::function<void()> func);
	std::function<void()> onClick;
};

