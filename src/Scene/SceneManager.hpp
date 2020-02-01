/*
**
** GLOBAL GAME JAM
**
*/

#ifndef SCENE_MANAGER_HPP
    #define SCENE_MANAGER_HPP

    #include <stack>
    #include "IScene.hpp"

class SceneManager {
public:
    SceneManager();
    SceneManager(SceneManager &) = delete;
    ~SceneManager();
    SceneManager &operator=(SceneManager &) = delete;

    void push(IScene::TypeScene type);
    void pop();
    std::shared_ptr<IScene> get();
    bool isEmpty() const;

private:
    std::stack<std::shared_ptr<IScene>> _scenes;
};

#endif /*SCENE_MANAGER_HPP*/
