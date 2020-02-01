/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ANIMATEDGAMEOBJECT_HPP
    #define ANIMATEDGAMEOBJECT_HPP

    #include "AGameObject.hpp"

class AnimatedGameObject : public AGameObject {
public:
    // Constructors
    AnimatedGameObject(const std::string &);
    AnimatedGameObject(const AnimatedGameObject &);
    AnimatedGameObject &operator=(const AnimatedGameObject &);
    virtual ~AnimatedGameObject() = default;

    // Setters & Getters
    void setCurrentAnimation(const std::string &);
    void setCurrentFrame(std::size_t);

    // Methods
    void update();
    void addFrame(const Animation &, Frame);
    void addFrames(const Animation &, Frames, float);
    
protected:
    // Variables
    Animations _anims;
    std::string _currentAnimation;
    std::size_t _currentFrame;
    float _elapsed;

};

#endif /*ANIMATEDGAMEOBJECT_HPP*/
