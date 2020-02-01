/*
**
** GLOBAL GAME JAM
**
*/

#include "AScene.hpp"

AScene::AScene(IScene::TypeScene)
{

}

IScene::TypeScene AScene::getType() const
{
    return _type;
}

