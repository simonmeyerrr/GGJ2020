#ifndef ASCENE_HPP
    #define ASCENE_HPP
    #include "IScene.hpp"

class AScene : virtual public IScene {
public:
    AScene(IScene::TypeScene);
    AScene(AScene &) = delete;
    virtual ~AScene() = default;

    AScene &operator=(const AScene &) = delete;
    TypeScene getType() const;

private:
    TypeScene _type;

    const std::vector<std::shared_ptr<IGameObject>> _gameObject;
    const std::vector<std::shared_ptr<ISoundObject>> _soundObject;
    const std::vector<std:shared_ptr<IUIObject>> _uiObject;
};

#endif /*ASCENE_HPP*/