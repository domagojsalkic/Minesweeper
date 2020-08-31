#include "stdafx.h"
#include "Game.h"
#include "SFML/Main.hpp"

int main()
{
    srand(time(NULL));
    Game game;

    game.run();

    return 0;
}