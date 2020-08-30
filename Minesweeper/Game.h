#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <unordered_map>
#include "Cell.h"
#include "GameState.h"

#define STATS_SIZE 100
#define GRID_SIZE 600


class Game
{

public:

    void run();

    void startPressed(sf::Vector2i mousePos, GameState& gameState, sf::RenderWindow& window, sf::Vector2f gridPos, std::unordered_map<std::string, sf::Texture*>& textureMap);

    void drawStartButton(sf::RenderWindow& window);

    void drawTimer();
    void drawBombCount();

    void updateTimer(int seconds);
    void updateBombCounter(int bombs);

private:

    void deleteTextures();
    void initTextures();
    std::unordered_map<std::string, sf::Texture*> textureMap;
    sf::RectangleShape timer;
    sf::Text timerText;
    sf::RectangleShape bombCount;
    sf::Text bombCountText;
    sf::RectangleShape startButton;
    sf::Font font;

    
};

