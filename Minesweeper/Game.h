#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <unordered_map>
#include "Cell.h"

#define STATS_SIZE 100
#define GRID_SIZE 600
#define NUM_OF_BOMBS 10

static std::unordered_map<std::string, sf::Texture*> textureMap;


class Game
{

public:

    Game() = default;

    void run();




private:

    void initTextures();
    sf::RectangleShape timer;
    sf::Text timerText;
    sf::RectangleShape bombLeft;
    sf::Text bombLeftText;
    sf::RectangleShape startButton;
    sf::Event event;
    
};

