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
    ~SceneManager();
    SceneManager();
    SceneManager(SceneManager &) = delete;
    SceneManager &operator=(SceneManager &) = delete;

    void push(IScene::TypeScene type, IScene::Saves &);
    void pop();
    IScene *get();
    bool isEmpty() const;

private:
    std::stack<IScene *> _scenes;
};

#endif /*SCENE_MANAGER_HPP*/
