/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** TippingText.hpp
*/

#ifndef GGJ2020_TIPPINGTEXT_HPP
#define GGJ2020_TIPPINGTEXT_HPP

#include "Text.hpp"

class TippingText : public Text {

public:
    enum State {
        CLEAN,
        WRITTING,
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

private:
    std::string _str;
    std::size_t _nbLetters;
    State _state;

};

#endif /* GGJ2020_TIPPINGTEXT_HPP */
