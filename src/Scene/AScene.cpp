/*
**
** GLOBAL GAME JAM
**
*/

#include "AScene.hpp"

AScene::AScene(IScene::TypeScene type, Saves &save)
    : _type(type), _save(save), _font("./assets/font/coolvetica.ttf"),
    _gameObject(), _uiObject()
{

}

IScene::TypeScene AScene::getType() const
{
    return _type;
}

