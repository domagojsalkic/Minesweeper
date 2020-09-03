#pragma once
#include "stdafx.h"
#include "Cell.h"




class GameState
{
public:

    void initGameState(sf::RenderWindow& window, sf::Vector2f gridPosition, const std::unordered_map<std::string, sf::Texture*>& textureMap);

    void draw(sf::RenderWindow& window);

    void drawTextures(const std::unordered_map<std::string, sf::Texture*>& textureMap, Cell* explodedCell);

    void leftClick(sf::Vector2i mousePos, const std::unordered_map<std::string, sf::Texture*>& textureMap);

    void rightClick(sf::Vector2i mousePos, const std::unordered_map<std::string, sf::Texture*>& textureMap);

    bool isBombExploded() const;

    int bombLeft() const;

    void setContentOfCell(const int& bombsAround, const int& i, const int& j);

    void countBombsAround(int& bombsAround, const int& i, const int& j) const;

    void createGrid(sf::Vector2f gridPosition, const std::unordered_map<std::string, sf::Texture*>& textureMap);

    void setTextureOfCell(Cell& cell, const std::unordered_map<std::string, sf::Texture*>& textureMap);

private:
    void openCells(const std::unordered_map<std::string, sf::Texture*>& textureMap, std::string textureName, int index);
    void openCell(const std::unordered_map<std::string, sf::Texture*>& textureMap, Cell* cell);
    std::vector<std::vector<Cell*>> grid;
    bool bombExploded;
    int numOfCells;
    int numOfBombs;
    const float SIZE = 25;
};

