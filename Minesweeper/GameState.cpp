#include "stdafx.h"
#include "GameState.h"



void GameState::initGameState(sf::RenderWindow& window, sf::Vector2f gridPosition, std::unordered_map<std::string, sf::Texture*>& textureMap)
{
    bombExploded = false;
    for (auto cells : grid)
    {
        cells.clear();
    }
    grid.clear();

    numOfBombs = 0;
    numOfCells = window.getSize().x / SIZE;

    grid.resize(numOfCells, std::vector<Cell*>());
    int index = 0;

    for (int i = 0; i < numOfCells; i++)
    {
        grid[i].resize(numOfCells, nullptr);
        for (int j = 0; j < numOfCells; j++)
        {
            if (rand() % 8 == 0)
            {
                grid[i][j] = new Cell(index, textureMap.at("Cell"), CellContent::BOMB, sf::Vector2f(gridPosition.x + i * SIZE, gridPosition.y + j * SIZE));
                numOfBombs++;
            }
            else
                grid[i][j] = new Cell(index, textureMap.at("Cell"), CellContent::EMPTY, sf::Vector2f(gridPosition.x + i * SIZE, gridPosition.y + j * SIZE));
            index++;
        }
    }


    int bombsAround = 0;

    for (int i = 0; i < numOfCells; i++)
    {
        for (int j = 0; j < numOfCells; j++)
        {
            if (grid[i][j]->getContent() == CellContent::EMPTY)
            {
                if (i - 1 >= 0)
                {
                    if (grid[i - 1][j]->getContent() == CellContent::BOMB)
                    {
                        bombsAround++;
                    }
                    if (j - 1 >= 0)
                    {
                        if (grid[i - 1][j - 1]->getContent() == CellContent::BOMB)
                        {
                            bombsAround++;
                        }
                    }
                    if (j + 1 < numOfCells)
                    {
                        if (grid[i - 1][j + 1]->getContent() == CellContent::BOMB)
                        {
                            bombsAround++;
                        }
                    }
                }
                if (i + 1 < numOfCells)
                {
                    if (grid[i + 1][j]->getContent() == CellContent::BOMB)
                    {
                        bombsAround++;
                    }
                    if (j - 1 >= 0)
                    {
                        if (grid[i + 1][j - 1]->getContent() == CellContent::BOMB)
                        {
                            bombsAround++;
                        }
                    }
                    if (j + 1 < numOfCells)
                    {
                        if (grid[i + 1][j + 1]->getContent() == CellContent::BOMB)
                        {
                            bombsAround++;
                        }
                    }
                }
                if (j + 1 < numOfCells)
                {
                    if (grid[i][j + 1]->getContent() == CellContent::BOMB)
                    {
                        bombsAround++;
                    }
                }
                if (j - 1 >= 0)
                {
                    if (grid[i][j - 1]->getContent() == CellContent::BOMB)
                    {
                        bombsAround++;
                    }
                }

                switch (bombsAround)
                {
                case 1:
                    grid[i][j]->setContent(CellContent::ONE);
                    break;
                case 2:
                    grid[i][j]->setContent(CellContent::TWO);
                    break;
                case 3:
                    grid[i][j]->setContent(CellContent::THREE);
                    break;
                case 4:
                    grid[i][j]->setContent(CellContent::FOUR);
                    break;
                case 5:
                    grid[i][j]->setContent(CellContent::FIVE);
                    break;
                case 6:
                    grid[i][j]->setContent(CellContent::SIX);
                    break;
                case 7:
                    grid[i][j]->setContent(CellContent::SEVEN);
                    break;
                case 8:
                    grid[i][j]->setContent(CellContent::EIGHTH);
                    break;
                default:
                    break;
                }

            }
            bombsAround = 0;
        }
    }
}

void GameState::draw(sf::RenderWindow& window)
{
    for (auto cells : grid)
        for (auto cell : cells)
            window.draw(cell->getShape());
}

void GameState::drawTextures(std::unordered_map<std::string, sf::Texture*>& textureMap, Cell* explodedCell)
{
    for (auto cells : grid)
    {
        for (auto cell : cells)
        {
            if (cell->isFlagSet() && cell->getContent() == CellContent::BOMB)
            {
                cell->getShape().setTexture(textureMap.at("NotMine"));
            }
            else if (explodedCell->getIndex() == cell->getIndex())
            {
                cell->getShape().setTexture(textureMap.at("ExplodedMine"));
            }
            else
            {
                switch (cell->getContent())
                {
                case CellContent::BOMB:
                    cell->getShape().setTexture(textureMap.at("Mine"));
                    break;
                case CellContent::ONE:
                    cell->getShape().setTexture(textureMap.at("One"));
                    break;
                case CellContent::TWO:
                    cell->getShape().setTexture(textureMap.at("Two"));
                    break;
                case CellContent::THREE:
                    cell->getShape().setTexture(textureMap.at("Three"));
                    break;
                case CellContent::FOUR:
                    cell->getShape().setTexture(textureMap.at("Four"));
                    break;
                case CellContent::FIVE:
                    cell->getShape().setTexture(textureMap.at("Five"));
                    break;
                case CellContent::SIX:
                    cell->getShape().setTexture(textureMap.at("Six"));
                    break;
                case CellContent::SEVEN:
                    cell->getShape().setTexture(textureMap.at("Seven"));
                    break;
                case CellContent::EIGHTH:
                    cell->getShape().setTexture(textureMap.at("Eighth"));
                    break;
                case CellContent::EMPTY:
                    cell->getShape().setTexture(textureMap.at("Empty"));
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void GameState::leftClick(sf::Vector2i mousePos, std::unordered_map<std::string, sf::Texture*>& textureMap)
{
    for (int i = 0; i < numOfCells; i++)
    {
        for (int j = 0; j < numOfCells; j++)
        {
            if (grid[i][j]->getShape().getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                switch (grid[i][j]->getContent())
                {
                case CellContent::BOMB:
                    grid[i][j]->getShape().setTexture(textureMap.at("ExplodedMine"));
                    grid[i][j]->Open();
                    drawTextures(textureMap, grid[i][j]);
                    bombExploded = true;
                    break;
                case CellContent::EMPTY:
                    openCells(textureMap, "Empty", grid[i][j]->getIndex());
                    break;
                case CellContent::ONE:
                    openCell(textureMap, "One", grid[i][j]);
                    break;
                case CellContent::TWO:
                    openCell(textureMap, "Two", grid[i][j]);
                    break;
                case CellContent::THREE:
                    openCell(textureMap, "Three", grid[i][j]);
                    break;
                case CellContent::FOUR:
                    openCell(textureMap, "Four", grid[i][j]);
                    break;
                case CellContent::FIVE:
                    openCell(textureMap, "Five", grid[i][j]);
                    break;
                case CellContent::SIX:
                    openCell(textureMap, "Six", grid[i][j]);
                    break;
                case CellContent::SEVEN:
                    openCell(textureMap, "Seven", grid[i][j]);
                    break;
                case CellContent::EIGHTH:
                    openCell(textureMap, "Eighth", grid[i][j]);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void GameState::rightClick(sf::Vector2i mousePos, std::unordered_map<std::string, sf::Texture*>& textureMap)
{
    for (auto cells : grid)
    {
        for (auto cell : cells)
        {
            if (cell->getShape().getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                    cell->setFlag(textureMap);
                    if (cell->isFlagSet())
                        numOfBombs--;
                    else
                        numOfBombs++;
            }
        }
    }
}

bool GameState::isBombExploded()
{
    return bombExploded;
}

int GameState::bombLeft()
{
    return numOfBombs;
}


void GameState::openCells(std::unordered_map<std::string, sf::Texture*>& textureMap, std::string textureName, int index)
{
    for (int i = 0; i < numOfCells; i++)
    {
        for (int j = 0; j < numOfCells; j++)
        {
            if (grid[i][j]->getIndex() == index)
            {
                if (!grid[i][j]->isCellOpen())
                {
                    if (grid[i][j]->getContent() == CellContent::EMPTY && !grid[i][j]->isFlagSet())
                    {
                        grid[i][j]->Open();
                        grid[i][j]->getShape().setTexture(textureMap.at(textureName));
                        if (i - 1 >= 0)
                            openCells(textureMap, textureName, grid[i - 1][j]->getIndex());
                        if (j - 1 >= 0)
                            openCells(textureMap, textureName, grid[i][j - 1]->getIndex());
                        if (j + 1 < numOfCells)
                            openCells(textureMap, textureName, grid[i][j + 1]->getIndex());
                        if (i + 1 < numOfCells)
                            openCells(textureMap, textureName, grid[i + 1][j]->getIndex());
                    }
                }
            }
        }
    }

}

void GameState::openCell(std::unordered_map<std::string, sf::Texture*>& textureMap, std::string textureName, Cell* cell)
{
    if (!cell->isCellOpen() && !cell->isFlagSet())
    {
        cell->Open();
        cell->getShape().setTexture(textureMap.at(textureName));
    }
}
