//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_TEXT_HPP
    #define GGJ2020_TEXT_HPP

    #include "AUIObject.hpp"
    #include "SFML/Graphics/Font.hpp"
    #include "../../Utils/Using.hpp"
    #include <SFML/Graphics/Text.hpp>

#

class Text : virtual public AUIObject {
public:
    // Constructors
    Text(const std::string &, const sf::Font &, unsigned int characterSize = 30);
    ~Text() override = default;

    // Setters & Getters
    sf::Vector2f const &getPosition() const override;
    void setPosition(sf::Vector2f &) override;
    void setScale(const sf::Vector2f &) override;
    sf::Vector2f const &getScale() const override;
    void setOrigin(const sf::Vector2f &) override;
    sf::Vector2f const &getOrigin() const override;
    void setString(std::string const &);
    std::string getString() const;
    void setFont(sf::Font const &);
    sf::Font const *getFont() const;
    void setSize(size_t size);
    size_t getSize() const;
    void setLineSpacing(float spacing);
    float getLineSpacing() const;
    void setLetterSpacing(float spacing);
    float getLetterSpacing() const;

    // Methods
    void draw(sf::RenderWindow window) const override;

private:
    s_ptr<sf::Text> _text;
};


#endif //GGJ2020_TEXT_HPP
