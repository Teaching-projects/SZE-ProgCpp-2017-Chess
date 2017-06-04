#include "discoveredstep.h"

DiscoveredStep::DiscoveredStep() : DiscoveredStep(-1, -1) {}

DiscoveredStep::DiscoveredStep(int x, int y)
{
    this->x = x;
    this->y = y;
}

int DiscoveredStep::getX()
{
    return this->x;
}

int DiscoveredStep::getY()
{
    return this->y;
}
