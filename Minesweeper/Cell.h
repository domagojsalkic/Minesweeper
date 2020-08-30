#pragma once

#include "stdafx.h"



enum class CellContent
{
    EMPTY,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHTH,
    BOMB
};

class Cell
{
public:

    Cell();

    Cell(int index, sf::Texture* texture, CellContent content, sf::Vector2f position);

    sf::RectangleShape& getShape();

    Cell& operator= (const Cell&);

    bool isCellOpen();

    int getIndex();

    CellContent getContent();

    void setContent(CellContent c);

    void Open();

    bool isFlagSet();

    void setFlag(std::unordered_map<std::string, sf::Texture*>& textureMap);

private:
    sf::RectangleShape shape;
    CellContent content;
    bool isOpen;
    int index;
    bool isFlag;
};

