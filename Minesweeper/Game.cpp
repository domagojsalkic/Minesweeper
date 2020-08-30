#include "stdafx.h"
#include "Game.h"
#include "GameState.h"


#define STATS_SIZE 100
#define GRID_SIZE 500


void Game::run()
{
    initTextures();
    sf::RenderWindow window(sf::VideoMode(GRID_SIZE, GRID_SIZE + STATS_SIZE), "MineSweeper");
    window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);
    sf::Event event;
    sf::Clock clock;
    sf::Time time;
    GameState gameState;
    gameState.initGameState(window, sf::Vector2f(0, STATS_SIZE), textureMap);
    font.loadFromFile("Fonts/digital-7.ttf");

    drawStartButton(window);
    drawTimer();
    drawBombCount();


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            {

                if (event.key.code == sf::Mouse::Right)
                {
                    gameState.rightClick(sf::Mouse::getPosition(window), textureMap);
                }
            }
        }
        
        while (gameState.isBombExploded())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                startPressed(sf::Mouse::getPosition(window), gameState, window, sf::Vector2f(0, STATS_SIZE), textureMap);
                clock.restart();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        { 
            gameState.leftClick(sf::Mouse::getPosition(window), textureMap);
        }
        

        window.clear(sf::Color(200, 200, 200));
        time = clock.getElapsedTime();
        updateTimer(time.asSeconds());
        updateBombCounter(gameState.bombLeft());

        gameState.draw(window);

        window.draw(startButton);
        window.draw(timer);
        window.draw(bombCount);

        window.draw(timerText);
        window.draw(bombCountText);


        window.display();
    }
    deleteTextures();
}

void Game::startPressed(sf::Vector2i mousePos, GameState& gameState, sf::RenderWindow& window, sf::Vector2f gridPos, std::unordered_map<std::string, sf::Texture*>& textureMap)
{
    if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && gameState.isBombExploded())
    {
        gameState.initGameState(window, gridPos, textureMap);
    }
}

void Game::drawStartButton(sf::RenderWindow& window)
{
    startButton.setTexture(textureMap.at("StartButton"));
    startButton.setSize(sf::Vector2f(70, 70));
    startButton.setPosition(window.getSize().x / 2 - 35, STATS_SIZE / 2 - 35);
}

void Game::drawTimer()
{
    timer.setFillColor(sf::Color::Black);
    timer.setSize(sf::Vector2f(150, 70));
    timer.setPosition(sf::Vector2f(20, 15));
    timerText.setFont(font);
    timerText.setCharacterSize(50);
    timerText.setFillColor(sf::Color::Red);
    timerText.setString("0");
}

void Game::drawBombCount()
{
    bombCount.setFillColor(sf::Color::Black);
    bombCount.setSize(sf::Vector2f(150, 70));
    bombCount.setPosition(sf::Vector2f(500 - 170, 15));
    bombCountText.setFont(font);
    bombCountText.setCharacterSize(50);
    bombCountText.setFillColor(sf::Color::Red);
    bombCountText.setString("0");
}

void Game::updateTimer(int seconds)
{
    timerText.setString(std::to_string(seconds));
    timerText.setPosition(sf::Vector2f(timer.getGlobalBounds().width - timerText.getGlobalBounds().width - 5, timer.getGlobalBounds().height / 2 - timerText.getGlobalBounds().height / 2));
}

void Game::updateBombCounter(int bombs)
{
    bombCountText.setString(std::to_string(bombs));
    bombCountText.setPosition(sf::Vector2f(bombCount.getPosition().x + bombCount.getGlobalBounds().width - bombCountText.getGlobalBounds().width - 20, bombCount.getPosition().y ));
}

void Game::deleteTextures()
{
    textureMap.clear();
}

void Game::initTextures()
{
    sf::Texture* emptyCell(new sf::Texture());
    emptyCell->loadFromFile("Images\\EmptyCell.png");
    textureMap.emplace("Empty", std::move(emptyCell));
    sf::Texture* one(new sf::Texture());
    one->loadFromFile("Images\\One.png");
    textureMap.emplace("One", std::move(one));
    sf::Texture* two(new sf::Texture());
    two->loadFromFile("Images\\Two.png");
    textureMap.emplace("Two", std::move(two));
    sf::Texture* three(new sf::Texture());
    three->loadFromFile("Images\\Three.png");
    textureMap.emplace("Three", std::move(three));
    sf::Texture* four(new sf::Texture());
    four->loadFromFile("Images\\Four.png");
    textureMap.emplace("Four", std::move(four));
    sf::Texture* five(new sf::Texture());
    five->loadFromFile("Images\\Five.png");
    textureMap.emplace("Five", std::move(five));
    sf::Texture* six(new sf::Texture());
    six->loadFromFile("Images\\Six.png");
    textureMap.emplace("Six", std::move(six));
    sf::Texture* seven(new sf::Texture());
    seven->loadFromFile("Images\\Seven.png");
    textureMap.emplace("Seven", std::move(seven));
    sf::Texture* eight(new sf::Texture());
    eight->loadFromFile("Images\\Eighth.png");
    textureMap.emplace("Eighth", std::move(eight));
    sf::Texture* flag(new sf::Texture());
    flag->loadFromFile("Images\\Flag.png");
    textureMap.emplace("Flag", std::move(flag));
    sf::Texture* mine(new sf::Texture());
    mine->loadFromFile("Images\\Mine.png");
    textureMap.emplace("Mine", std::move(mine));
    sf::Texture* explodedMine(new sf::Texture());
    explodedMine->loadFromFile("Images\\ExplodedMine.png");
    textureMap.emplace("ExplodedMine", std::move(explodedMine));
    sf::Texture* notMine(new sf::Texture());
    notMine->loadFromFile("Images\\NotMine.png");
    textureMap.emplace("NotMine", std::move(notMine));
    sf::Texture* startButton(new sf::Texture());
    startButton->loadFromFile("Images\\StartButton.png");
    textureMap.emplace("StartButton", std::move(startButton));
    sf::Texture* cell(new sf::Texture());
    cell->loadFromFile("Images\\UnCheckedCell.png");
    textureMap.emplace("Cell", std::move(cell));
}
