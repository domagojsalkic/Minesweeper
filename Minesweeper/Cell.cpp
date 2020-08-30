#include "Cell.h"


Cell::Cell()
    : index(0),
    content(CellContent::EMPTY),
    isOpen(false),
    isFlag(false)
{

}

Cell::Cell(int index, sf::Texture* texture, CellContent content, sf::Vector2f position)
    : index(index),
    content(content),
    isOpen(false),
    isFlag(false)
{
    shape.setSize(sf::Vector2f(25, 25));
    shape.setPosition(position);
    shape.setTexture(texture);
}

sf::RectangleShape& Cell::getShape()
{
    return shape;
}

Cell& Cell::operator=(const Cell& other)
{
    index = other.index;
    content = other.content;
    isOpen = other.isOpen;
    shape = other.shape;
    return *this;
}

bool Cell::isCellOpen()
{
    return isOpen;
}

int Cell::getIndex()
{
    return index;
}

CellContent Cell::getContent()
{
    return content;
}

void Cell::setContent(CellContent c)
{
    content = c;
}

void Cell::Open()
{
    if (!isOpen)
        isOpen = true;
}

bool Cell::isFlagSet()
{
    return isFlag;
}

void Cell::setFlag(std::unordered_map<std::string, sf::Texture*>& textureMap)
{
    if (isFlag)
    {
        isFlag = !isFlag;
        shape.setTexture(textureMap.at("Cell"));
    }
    else
    {
        isFlag = !isFlag;
        shape.setTexture(textureMap.at("Flag"));
    }
}
