/*
**
** GLOBAL GAME JAM
**
*/

#include "SceneManager.hpp"
#include "Intro.hpp"
#include "MainMenu.hpp"
#include "Settings.hpp"

SceneManager::SceneManager()
    : _scenes()
{
}

SceneManager::~SceneManager() {
    while (!isEmpty()) {
        delete _scenes.top();
        _scenes.pop();
    }
}

void SceneManager::push(IScene::TypeScene type) {
    switch (type) {
        case IScene::SCENE_INTRO:
            _scenes.push(new Intro());
            break;
        case IScene::SCENE_MAIN_MENU:
            _scenes.push(new MainMenu());
            break;
        case IScene::SCENE_SETTINGS:
            _scenes.push(new Settings());
            break;
        default:
            break;
    }
}

void SceneManager::pop() {
    delete _scenes.top();
    _scenes.pop();
    if (!isEmpty())
        _scenes.top()->resume();
}

IScene *SceneManager::get() {
    return isEmpty() ? nullptr : _scenes.top();
}

bool SceneManager::isEmpty() const {
    return _scenes.empty();
}
