/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** TippingText.hpp
*/

#ifndef GGJ2020_TIPPINGTEXT_HPP
#define GGJ2020_TIPPINGTEXT_HPP

#include "Text.hpp"
#include "Sprite.hpp"

class TippingText : public Text {
public:
    enum State {
        CLEAN,
        WRITING,
        ENDED,
    };
    TippingText(const std::string &, const sf::Font &, const sf::Vector2f &, const sf::Color & = sf::Color::Black, unsigned int = 30);
    TippingText &operator=(TippingText const &);

    ~TippingText() override = default;

    void setString(std::string const &) override;
    void update() override;
    void start();
    void clean();
    State getState() const;
    void drawAll(sf::RenderWindow &window) const;
    void draw(sf::RenderWindow &w) const override;

private:
    std::string _str;
    std::size_t _nbLetters;
    State _state;
    sf::Sprite _s;
    sf::Texture _t;

};

#endif /* GGJ2020_TIPPINGTEXT_HPP */
