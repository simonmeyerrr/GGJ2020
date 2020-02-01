/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ASCENE_HPP
    #define ASCENE_HPP

    #include "IScene.hpp"
    #include "../Object/UIObject/IUIObject.hpp"
    #include "../Utils/FontLoader.hpp"

class AScene : public IScene {
public:
    // Constructors
    AScene(IScene::TypeScene);
    AScene(AScene &) = delete;
    virtual ~AScene() override = default;
    AScene &operator=(const AScene &) = delete;

    // Setters & Getters
    TypeScene getType() const override;

protected:
    // Variable
    TypeScene _type;
    FontLoader _font;

    //std::vector<std::shared_ptr<IGameObject>> _gameObject;
    //std::vector<std::shared_ptr<ISoundObject>> _soundObject;
    std::map<int, std::shared_ptr<IUIObject>> _uiObject;
};

#endif /*ASCENE_HPP*/