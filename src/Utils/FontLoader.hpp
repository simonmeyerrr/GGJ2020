#ifndef GGJ2020_FONTLOADER_HPP
#define GGJ2020_FONTLOADER_HPP

#include <string>
#include <SFML/Graphics.hpp>

class FontLoader {
public:
    ~FontLoader() = default;
    explicit FontLoader(const std::string &path)
    : _font(std::make_unique<sf::Font>())
    {
        _font->loadFromFile(path);
    }

    sf::Font &get() {return *_font;}
    const sf::Font &get() const {return *_font;}

private:
    std::unique_ptr<sf::Font> _font;
};


#endif /* GGJ2020_FONTLOADER_HPP */
