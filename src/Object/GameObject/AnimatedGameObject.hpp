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
    AnimatedGameObject(const std::string &, sf::Time = sf::seconds(0.2f));
    AnimatedGameObject(const AnimatedGameObject &);
    AnimatedGameObject &operator=(const AnimatedGameObject &);
    virtual ~AnimatedGameObject() = default;

    // Setters & Getters
    void setCurrentAnimation(const std::string &);
    void setCurrentFrame(std::size_t);

    // Methods
    void update(sf::Time);
    void addFrame(const Animation &, Frame);
    void addFrames(const Animation &, Frames);
    
protected:
    // Variables
    Animations _anims;
    std::string _currentAnimation;
    std::size_t _currentFrame;
    sf::Time _frameTime;
    sf::Time _elapsedTime;

};

#endif /*ANIMATEDGAMEOBJECT_HPP*/
