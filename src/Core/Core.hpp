/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CORE_HPP
    #define CORE_HPP

    #include "../Scene/SceneManager.hpp"
    #include <string>
    #include <bits/unique_ptr.h>

class Core {
public:
    Core();
    Core(Core &) = delete;
    ~Core();
    Core &operator=(Core &) = delete;

private:
    std::unique_ptr<SceneManager> _sceneManager;
};

#endif /*CORE_HPP*/
