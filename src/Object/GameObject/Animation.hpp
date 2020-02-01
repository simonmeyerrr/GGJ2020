/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ANIMATION_HPP
    #define ANIMATION_HPP

    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <vector>
    #include <string>

using frame = sf::IntRect;
using frames = std::vector<frame>;

class Animation {
public:
    // Constructors
    Animation();
    Animation(const Animation &);
    Animation &operator=(const Animation &);
    ~Animation();

    // Setters & Getters
    void setTexture(const sf::Texture *);
    
    const sf::Texture* getTexture() const;
    const frames &getFrames() const;
    const frame &getFrame(std::size_t) const;
    std::size_t getSize() const;

    // Methods
    void addFrame(const frame &);

private:
    // Variables
    frames _frames;
    const sf::Texture *_t;

};

#endif /*ANIMATION_HPP*/
