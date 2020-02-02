/*
**
** GLOBAL GAME JAM
**
*/

#include "SceneManager.hpp"
#include "Intro.hpp"
#include "MainMenu.hpp"
#include "LevelTwo.hpp"
#include "LevelOne.hpp"
#include "LevelThree.hpp"

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

void SceneManager::push(IScene::TypeScene type, IScene::Saves &save) {
    switch (type) {
        case IScene::SCENE_INTRO:
            _scenes.push(new Intro(save));
            break;
        case IScene::SCENE_MAIN_MENU:
            _scenes.push(new MainMenu(save));
            break;
        case IScene::SCENE_LEVEL1:
            _scenes.push(new LevelOne(save));
            break;
        case IScene::SCENE_LEVEL2:
            _scenes.push(new LevelTwo(save));
            break;
        case IScene::SCENE_LEVEL3:
            _scenes.push(new LevelThree(save));
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
