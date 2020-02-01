//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_BUTTON_HPP
    #define GGJ2020_BUTTON_HPP


    #include "IUIObject.hpp"
    #include "Text.hpp"
    #include "Sprite.hpp"

class Button : virtual public IUIObject {
public:

    enum State {
        NONE,
        HOVER,
        CLICKED
    };

    using LambdaMethod = std::function<void ()>;

    // Constructors
    Button(const Text &, const Sprite &, LambdaMethod &);
    ~Button() override = default;

    // Setters & Getters
    Text &getText() const;
    void setText(const Text &);
    Sprite &getSprite() const;
    void setSprite(const Sprite &);

    // Operators

    // Methods
    void draw(sf::RenderWindow &window) const override;
    void cb();

private:
    LambdaMethod _function;
    State _state;
    Text *_text;
    Sprite *_sprite;
};


#endif //GGJ2020_BUTTON_HPP