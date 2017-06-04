#ifndef DISCOVEREDSTEP_H
#define DISCOVEREDSTEP_H

class DiscoveredStep
{
private:
    int x;
    int y;

public:
    DiscoveredStep();
    DiscoveredStep(int x, int y);

    int getX();
    int getY();
};

#endif // DISCOVEREDSTEP_H
