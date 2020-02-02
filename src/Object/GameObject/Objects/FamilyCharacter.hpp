//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#ifndef GGJ2020_FAMILYCHARACTER_HPP
#define GGJ2020_FAMILYCHARACTER_HPP


#include "../AnimatedGameObject.hpp"

class FamilyCharacter : public AnimatedGameObject {
public:
    // Constructors
    FamilyCharacter(std::string const &);
    FamilyCharacter(const FamilyCharacter &) = delete;
    FamilyCharacter &operator=(const FamilyCharacter &) = delete;
    virtual ~FamilyCharacter() = default;

    // Getters & Setters
    void setTalking(bool);
    void setPosition(sf::Vector2f);

    // Methods
    void move(float max, float ratio);

private:
    bool _isTalking;
    sf::Vector2f _pos;
    sf::Vector2f _basePos;
    bool _right;
};


#endif //GGJ2020_FAMILYCHARACTER_HPP
