/*
**
** GLOBAL GAME JAM
**
*/

#include "MainMenu.hpp"

MainMenu::MainMenu()
        : AScene(SCENE_MAIN_MENU)
{

}

IScene::Event MainMenu::update()
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event MainMenu::event(sf::RenderWindow &, sf::Event &)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void MainMenu::display(sf::RenderWindow &)
{}

void MainMenu::resume()
{}

