//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#include "FamilyCharacter.hpp"

FamilyCharacter::FamilyCharacter(std::string const &fileName, size_t size, sf::Font &font, sf::Vector2f pos)
: AnimatedGameObject(fileName), _tipping(_font)
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
    _isFound = true;
    _isTalking = false;
    _quests.reserve(size);
    _font = font;
    setPosition(pos);
    setCurrentAnimation("idleRight");
}

void FamilyCharacter::addQuest(std::string const &s) {
    _quests.push_back(s);
}

void FamilyCharacter::setTalking(bool talking) {
    _isTalking = talking;
}

void FamilyCharacter::move(float max, float ratio) {
    if (_tipping.getState() == TippingText::CLEAN) {
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

    if (_isFound) {
        _tipping.start(_quests[idx]);
        _isFound = false;
    } else {
        _tipping.start("Reviens me voir plus tard quand tu auras\nretrouve l'objet !");
    }
}

void FamilyCharacter::draw(sf::RenderWindow &w) {
    _tipping.draw(w);
}

void FamilyCharacter::updateBubble() {
    _tipping.update();
}

void FamilyCharacter::successQuest() {
    _isFound = true;
    _tipping.start("Merci beaucoup pour avoir retrouve\n cet objet!");
}
