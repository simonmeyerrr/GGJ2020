/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ASCENE_HPP
    #define ASCENE_HPP

    #include "IScene.hpp"
    #include "../Object/GameObject/IGameObject.hpp"
    #include "../Object/SoundObject/ISoundObject.hpp"
    #include "../Object/UIObject/IUIObject.hpp"

class AScene : virtual public IScene {
public:
    // Constructors
    AScene(IScene::TypeScene);
    AScene(AScene &) = delete;
    virtual ~AScene() = default;

    // Setters & Getters
    AScene &operator=(const AScene &) = delete;
    TypeScene getType() const;

private:
    // Variable
    TypeScene _type;

    std::vector<std::shared_ptr<IGameObject>> _gameObject;
    std::vector<std::shared_ptr<ISoundObject>> _soundObject;
    std::vector<std::shared_ptr<IUIObject>> _uiObject;
};

#endif /*ASCENE_HPP*/