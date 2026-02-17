#ifdef _WIN32
#include <windows.h>
#endif

#include <time.h>
#include <iostream>

#include "fogpi/Math.hpp"

#include "Dice.hpp"
#include "Entity.hpp"

#include "DataStructures/LinkList.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello, Class" << std::endl;

    Vec2 v;
    v.x = 5.0f;

    // random seed
    srand(time(NULL));

    Die die = { .sides = 8 };

    std::vector<Die> dice;
    dice.push_back(die);
    dice.push_back(die);
    dice.push_back(die);

    RollStats stats = RollDice(dice);
    
    return 0;
}
