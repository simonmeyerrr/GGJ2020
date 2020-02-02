//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#include "LevelThree.hpp"
#include "../Object/GameObject/Objects/FamilyCharacter.hpp"
#include "../Object/GameObject/Objects/PlayerSchool.hpp"

#define DOOR_HEIGHT 300
#define DOOR_WIDTH 200
#define PLAYER_HEIGHT 300
#define PLAYER_WIDTH  300
#define HEIGHT 700
#define DIFF 50
#define CHARPOS _gameObject[CHARACTER]->getPosition()

IScene::Event LevelThree::update() {
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->updateBubble();
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->updateBubble();
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->updateBubble();
    for (auto &elem : _gameObject) {
        elem.second->update();
    }
    if (_walking) {
        if (!_right && _pos.x > -DIFF)
            _pos.x -= 3;
        else if (_right && _pos.x < 1600 - PLAYER_WIDTH + DIFF)
            _pos.x += 3;
        _gameObject[CHARACTER]->setPosition(_pos);
    }
    if (_talking) {
        for (auto &charac : _gameObject) {
            if (dynamic_cast<FamilyCharacter *>(charac.second.get())
            && (CHARPOS.x >= charac.second->getPosition().x
            && CHARPOS.x <= charac.second->getPosition().x + charac.second->getSprite().getTextureRect().width)) {
                _talking = false;
                dynamic_cast<FamilyCharacter *>(charac.second.get())->askQuest(_quests[(Type)charac.first]);
                break;
            }
        }
        _talking = false;
    }
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelThree::event(sf::RenderWindow &w, sf::Event &e) {
    if (e.type == sf::Event::KeyPressed) {
        if (!_walking && (e.key.code == sf::Keyboard::Right ||
        e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("walk") + (_right ? "Right" : "Left"));
        }
        if (e.key.code == sf::Keyboard::Enter) {
            _talking = !_talking;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right))) {
            _walking = false;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(
                    std::string("idle") + (_right ? "Right" : "Left"));
        }
    }
    return {EVENT_NONE, SCENE_INTRO};}

void LevelThree::display(sf::RenderWindow &w, shaders_map &s) {
    for (auto &item : _gameObject) {
        w.draw(item.second->getSprite());
    }
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->draw(w);
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->draw(w);
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->draw(w);
}

void LevelThree::resume() {

}

LevelThree::LevelThree(IScene::Saves &save) : AScene(SCENE_LEVEL3, save) {
    _gameObject[MOTHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 2, _font.get(), sf::Vector2f{0, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest2");
    _gameObject[FATHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 2, _font.get(), sf::Vector2f{600, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest2");
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest3");
    _gameObject[BROTHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 2, _font.get(), sf::Vector2f{1200, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->addQuest("quest2");
    _gameObject[CHARACTER] = std::make_shared<PlayerSchool>();
    _gameObject[CHARACTER]->setPosition({100, HEIGHT - PLAYER_HEIGHT});
    _pos = _gameObject[CHARACTER]->getPosition();
    _walking = false;
    _right = true;
    _talking = false;
    _quests[MOTHER] = 0;
    _quests[FATHER] = 0;
    _quests[BROTHER] = 0;
    dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
}