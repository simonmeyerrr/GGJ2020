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
    AnimatedGameObject(sf::Time = sf::seconds(0.2f), bool = false, bool = true);
    AnimatedGameObject(const AnimatedGameObject &);
    AnimatedGameObject &operator=(const AnimatedGameObject &);
    virtual ~AnimatedGameObject() = default;

    // Setters & Getters
    bool isPaused() const;
    bool isLooped() const;

    void setPaused(bool);
    void setLooped(bool);

    // Methods
    void update(sf::Time);
    void play();
    void play(const Animation &);
    void pause();
    void stop();

private:
    bool _isPaused;
    bool _isLooped;
};

#endif /*ANIMATEDGAMEOBJECT_HPP*/
