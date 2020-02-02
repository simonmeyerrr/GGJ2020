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
    TippingText(const sf::Font &font);
    TippingText &operator=(TippingText const &) = delete;

    ~TippingText() override = default;

    void update() override;
    void start(const std::string &str);
    void clean();
    State getState() const;
    void draw(sf::RenderWindow &w) const override;

private:
    std::string _str;
    std::size_t _nbLetters;
    State _state;
    sf::Sprite _s;
    sf::Texture _t;

};

#endif /* GGJ2020_TIPPINGTEXT_HPP */
