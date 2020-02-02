//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#include "FamilyCharacter.hpp"

FamilyCharacter::FamilyCharacter(std::string const &fileName, size_t size, sf::Font &font, sf::Vector2f pos)
: AnimatedGameObject(fileName)
{
    Frames idleRight;
    Frames idleLeft;
    Frames walkRight;
    Frames walkLeft;
    for (int i = 0; i < 1; ++i) {
        idleRight.push_back(sf::IntRect(i * 600, 0, 600, 600));
        idleLeft.push_back(sf::IntRect(i * 600, 600, 600, 600));
        walkRight.push_back(sf::IntRect(i * 600, 1200, 600, 600));
        walkLeft.push_back(sf::IntRect(i * 600, 1800, 600, 600));
    }
    addFrames("idleRight", idleRight, 0.03f);
    addFrames("idleLeft", idleLeft, 0.03f);
    addFrames("walkRight", walkRight, 0.035f);
    addFrames("walkLeft", walkLeft, 0.035f);
    setCurrentAnimation("walkRight");
    _pos = pos;
    _basePos = pos;
    _right = true;
    _isTalking = false;
    _quests.reserve(size);
    _font = font;
    setPosition(pos);
    setCurrentAnimation("idleRight");
    _notFound = std::make_shared<TippingText>("Reviens me voir quand tu auras trouvé !", font, pos, sf::Color::Black, 60);
    _successFull = std::make_shared<TippingText>("Tu as réussi à retrouver tous les objets perdus !", font, pos, sf::Color::Black, 60);
}

void FamilyCharacter::addQuest(std::string const &s) {
    _quests.push_back(std::make_shared<TippingText>(s, _font, sf::Vector2f(0, 0), sf::Color::Black, 60));
}

void FamilyCharacter::setTalking(bool talking) {
    _isTalking = talking;
}

void FamilyCharacter::move(float max, float ratio) {
    if (!_isTalking) {
        if (_right) {
            setCurrentAnimation("walkLeft");
            _pos.x += ratio;
            if (_pos.x >= _basePos.x + max) {
                _right = false;
            }
        } else {
            _pos.x -= ratio;
            if (_pos.x <= _basePos.x - max)
                _right = true;
            setCurrentAnimation("walkLeft");
        }
        _s.setPosition(_pos);
    }
}

void FamilyCharacter::setPosition(sf::Vector2f f) {
    _pos = f;
    _basePos = f;
    _s.setPosition(f);
}

void FamilyCharacter::askQuest(size_t idx) {
    _quests[idx]->start();
}

void FamilyCharacter::draw(sf::RenderWindow &w) {
    for (auto &elem : _quests) {
        elem->drawAll(w);
    }
    _successFull->drawAll(w);
    _notFound->drawAll(w);
}

void FamilyCharacter::updateBubble() {
    for (auto &elem : _quests) {
        elem->update();
    }
    _successFull->update();
    _notFound->update();;
}
