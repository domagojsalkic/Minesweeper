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
    EIGHT,
    BOMB
};

class Cell
{
public:

    Cell();

    Cell(int index, sf::Texture* texture, CellContent content, sf::Vector2f position);

    ~Cell() = default;

    sf::RectangleShape& getShape();

    Cell& operator= (const Cell&);

    bool isCellOpen() const;

    int getIndex() const;

    CellContent getContent() const;

    void setContent(CellContent c);

    void Open();

    bool isFlagSet() const;

    void setFlag(const std::unordered_map<std::string, sf::Texture*>& textureMap);


private:
    sf::RectangleShape shape;
    CellContent content;
    bool isOpen;
    int index;
    bool isFlag;
};

