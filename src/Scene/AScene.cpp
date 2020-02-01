/*
**
** GLOBAL GAME JAM
**
*/

#include "AScene.hpp"

AScene::AScene(IScene::TypeScene type)
    : _type(type), _font("./assets/font/coolvetica.ttf"),
    _gameObject(), _uiObject()
{

}

IScene::TypeScene AScene::getType() const
{
    return _type;
}

