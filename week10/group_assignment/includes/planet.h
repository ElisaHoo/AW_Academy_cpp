#ifndef PLANET_H
#define PLANET_H

struct Position
{
    int x{0};
    int y{0};
    int z{0};
};

class Planet
{
public:
    Planet(int x, int y, int z)
    {
        current_position.x = x;
        current_position.y = y;
        current_position.z = z;
    }
    Position current_position{};
    Position velocity{};
};

#endif
