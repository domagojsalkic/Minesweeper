#include "Game.h"
#include "GameState.h"


#define STATS_SIZE 100
#define GRID_SIZE 500



void Game::run()
{
    initTextures();
    sf::RenderWindow window(sf::VideoMode(GRID_SIZE, GRID_SIZE + STATS_SIZE), "MS");
    window.setFramerateLimit(30);
    GameState gameState;
    gameState.initGameState(window, sf::Vector2f(0, STATS_SIZE), textureMap);
    startButton.setTexture(textureMap.at("StartButton"));
    startButton.setSize(sf::Vector2f(70, 70));
    startButton.setPosition(window.getSize().x/2 - 35, STATS_SIZE / 2 - 35);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        while (gameState.isBombExploded())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
            {
                gameState.initGameState(window, sf::Vector2f(0, STATS_SIZE), textureMap);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            gameState.leftClick(sf::Mouse::getPosition(window), textureMap);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            gameState.rightClick(sf::Mouse::getPosition(window), textureMap);
        }


        window.clear(sf::Color(200, 200, 200));

        
        gameState.draw(window);

        window.draw(startButton);

        window.display();
    }

}

void Game::initTextures()
{
    sf::Texture* emptyCell(new sf::Texture());
    emptyCell->loadFromFile("Images\\EmptyCell.png");
    textureMap.emplace("Empty", emptyCell);
    sf::Texture* one(new sf::Texture());
    one->loadFromFile("Images\\One.png");
    textureMap.emplace("One", one);
    sf::Texture* two(new sf::Texture());
    two->loadFromFile("Images\\Two.png");
    textureMap.emplace("Two", two);
    sf::Texture* three(new sf::Texture());
    three->loadFromFile("Images\\Three.png");
    textureMap.emplace("Three", three);
    sf::Texture* four(new sf::Texture());
    four->loadFromFile("Images\\Four.png");
    textureMap.emplace("Four", four);
    sf::Texture* five(new sf::Texture());
    five->loadFromFile("Images\\Five.png");
    textureMap.emplace("Five", five);
    sf::Texture* six(new sf::Texture());
    six->loadFromFile("Images\\Six.png");
    textureMap.emplace("Six", six);
    sf::Texture* seven(new sf::Texture());
    seven->loadFromFile("Images\\Seven.png");
    textureMap.emplace("Seven", seven);
    sf::Texture* eight(new sf::Texture());
    eight->loadFromFile("Images\\Eighth.png");
    textureMap.emplace("Eighth", eight);
    sf::Texture* flag(new sf::Texture());
    flag->loadFromFile("Images\\Flag.png");
    textureMap.emplace("Flag", flag);
    sf::Texture* mine(new sf::Texture());
    mine->loadFromFile("Images\\Mine.png");
    textureMap.emplace("Mine", mine);
    sf::Texture* explodedMine(new sf::Texture());
    explodedMine->loadFromFile("Images\\ExplodedMine.png");
    textureMap.emplace("ExplodedMine", explodedMine);
    sf::Texture* notMine(new sf::Texture());
    notMine->loadFromFile("Images\\NotMine.png");
    textureMap.emplace("NotMine", notMine);
    sf::Texture* startButton(new sf::Texture());
    startButton->loadFromFile("Images\\StartButton.png");
    textureMap.emplace("StartButton", startButton);
    sf::Texture* cell(new sf::Texture());
    cell->loadFromFile("Images\\UnCheckedCell.png");
    textureMap.emplace("Cell", cell);
}
