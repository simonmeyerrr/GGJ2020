//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#ifndef GGJ2020_FAMILYCHARACTER_HPP
#define GGJ2020_FAMILYCHARACTER_HPP


#include "../AnimatedGameObject.hpp"
#include "../../UIObject/TippingText.hpp"

class FamilyCharacter : public AnimatedGameObject {
public:
    // Constructors
    FamilyCharacter(std::string const &, size_t size, sf::Font &font, sf::Vector2f);
    FamilyCharacter(const FamilyCharacter &) = delete;
    FamilyCharacter &operator=(const FamilyCharacter &) = delete;
    virtual ~FamilyCharacter() = default;

    // Getters & Setters
    void setTalking(bool);
    void setPosition(sf::Vector2f);

    // Methods
    void updateBubble();
    void move(float max, float ratio);
    void addQuest(std::string const &);
    void askQuest(size_t idx);
    void draw(sf::RenderWindow &w);

private:
    bool _isTalking;
    sf::Vector2f _pos;
    sf::Vector2f _basePos;
    bool _right;
    std::vector<std::shared_ptr<TippingText>> _quests;
    std::shared_ptr<TippingText> _notFound;
    std::shared_ptr<TippingText> _successFull;
    bool _isFound;
    sf::Font _font;
};


#endif //GGJ2020_FAMILYCHARACTER_HPP
