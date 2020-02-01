//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_TEXT_HPP
    #define GGJ2020_TEXT_HPP

    #include "IUIObject.hpp"
    #include "SFML/Graphics/Font.hpp"
    #include "../../Utils/Using.hpp"
    #include <SFML/Graphics/Text.hpp>

#

class Text : public IUIObject {
public:
    // Constructors
    Text(const std::string &, const sf::Font &, const sf::Vector2f &pos, const sf::Color &color = sf::Color::Black, unsigned int characterSize = 30);
    ~Text() override = default;

    // Setters & Getters
    sf::Vector2f const &getPosition() const;
    void setPosition(const sf::Vector2f &);
    virtual void setString(std::string const &);
    std::string getString() const;

    // Operators
    Text &operator=(Text const &text);

    // Methods
    void update() override;
    void event(sf::RenderWindow &window, sf::Event &) override;
    void draw(sf::RenderWindow &window) const override;

protected:
    s_ptr<sf::Text> _text;
};


#endif //GGJ2020_TEXT_HPP
