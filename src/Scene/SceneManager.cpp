/*
**
** GLOBAL GAME JAM
**
*/

#include <bits/shared_ptr.h>
#include "SceneManager.hpp"

SceneManager::SceneManager()
    : _scenes()
{
}

SceneManager::~SceneManager() {

}

void SceneManager::push(IScene::TypeScene type) {
    switch (type) {
        case IScene::TypeScene::INTRO:
            //_scenes.push(std::make_shared<Intro>());
        case IScene::TypeScene::MAIN_MENU:
            //_scenes.push(std::make_shared<MainMenu>());
        case IScene::TypeScene::SETTINGS:
            ;
            //_scenes.push(std::make_shared<Settings>());
    }
}

void SceneManager::pop() {
    _scenes.pop();
    if (!_scenes.empty()) {
        //_scenes.top()->resume();
    }
}

std::shared_ptr<IScene> SceneManager::get() {
    return _scenes.top();
}

bool SceneManager::isEmpty() const {
    return _scenes.empty();
}
