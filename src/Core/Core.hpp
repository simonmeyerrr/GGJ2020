/*
**
** GLOBAL GAME JAM
**
*/

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


// IScene _currentScene
// get / set

// vector IScene;
