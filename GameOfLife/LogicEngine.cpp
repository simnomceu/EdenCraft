#include "LogicEngine.hpp"

#include <utility>
#include <iostream>

#include "Message.hpp"

using namespace core::eng;
using namespace app::eng;
using namespace app::def;
using namespace core::com;

LogicEngine::LogicEngine(const bool activeIn, const int refreshRateIn): Engine(activeIn, refreshRateIn, "logic")
{
}


LogicEngine::~LogicEngine()
{
}

void app::eng::LogicEngine::initialize()
{
}

void app::eng::LogicEngine::process(std::shared_ptr<core::com::AbstractMessage> messageIn)
{
}

void app::eng::LogicEngine::update()
{
}

void app::eng::LogicEngine::render()
{
}
