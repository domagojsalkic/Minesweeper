#pragma once

#include "Cell.h"
#include <vector>
#include <unordered_map>



class GameState
{
public:

    void initGameState(sf::RenderWindow& window, sf::Vector2f gridPosition, std::unordered_map<std::string, sf::Texture*>& textureMap);

    void draw(sf::RenderWindow& window);

    void drawTextures(std::unordered_map<std::string, sf::Texture*>& textureMap, Cell* explodedCell);

    void leftClick(sf::Vector2i mousePos, std::unordered_map<std::string, sf::Texture*>& textureMap);

    void rightClick(sf::Vector2i mousePos, std::unordered_map<std::string, sf::Texture*>& textureMap);

    bool isBombExploded();

    void startGame(sf::Vector2i mousePos);

private:
    void openCells(std::unordered_map<std::string, sf::Texture*>& textureMap, std::string textureName, int index);
    void openCell(std::unordered_map<std::string, sf::Texture*>& textureMap, std::string textureName, Cell* cell);
    std::vector<std::vector<Cell*>> grid;
    std::vector<std::vector<Cell*>> evidenceGrid;
    bool bombExploded;
    int numOfCells;
    const float SIZE = 25;
};

