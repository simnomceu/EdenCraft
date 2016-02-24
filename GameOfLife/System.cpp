#include "System.hpp"

using namespace core::sys;
using namespace core::cmp;
using namespace core::ent;
using namespace core::rsc;
using namespace core::cmn;

System::System(): ComponentUser(), EntityUser(), Philosopher<ResourceManager>()
{
}


System::~System()
{
}
