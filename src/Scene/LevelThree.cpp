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
    if (_isTalking) {
        dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->updateBubble();
        dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->updateBubble();
        dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->updateBubble();
    }
    for (auto &elem : _gameObject) {
        elem.second->update();
    }
    if (_take) {
        ObjectType toDelete = NONE;
        for (auto &elem : _objects) {
            std::cout << "pos: " << std::endl;
            std::cout << CHARPOS.x << " & " << elem.second->getPosition().x << std::endl;
            std::cout << CHARPOS.x  + _gameObject[CHARACTER]->getSprite().getTextureRect().width << " & " << elem.second->getPosition().x << std::endl;
            if (CHARPOS.x <= elem.second->getPosition().x
            && CHARPOS.x + _gameObject[CHARACTER]->getSprite().getTextureRect().width / 2 >= elem.second->getPosition().x) {
                _hand = elem.first;
                toDelete = elem.first;
                break;
            }
        }
        if (_hand != NONE) {
            _objects.erase(toDelete);
            _hasTaken = true;
        }
        _take = false;
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
                if (charac.first == MOTHER && _hasTaken) {
                    if (_hand == _objMother[_quests[MOTHER]]) {
                        dynamic_cast<FamilyCharacter *>(charac.second.get())->successQuest();
                        _talking = false;
                        _hasTaken = false;
                        _quests[MOTHER] += 1;
                        _hand = NONE;
                        break;
                    }
                }
                if (charac.first == FATHER && _hasTaken) {
                    if (_hand == _objMother[_quests[FATHER]]) {
                        dynamic_cast<FamilyCharacter *>(charac.second.get())->successQuest();
                        _talking = false;
                        _hasTaken = false;
                        _quests[FATHER] += 1;
                        _hand = NONE;
                        break;
                    }
                }
                if (charac.first == BROTHER && _hasTaken) {
                    if (_hand == _objMother[_quests[BROTHER]]) {
                        dynamic_cast<FamilyCharacter *>(charac.second.get())->successQuest();
                        _talking = false;
                        _quests[BROTHER] += 1;
                        _hasTaken = false;
                        _hand = NONE;
                        break;
                    }
                }
                _talking = false;
                dynamic_cast<FamilyCharacter *>(charac.second.get())->askQuest(_quests[(Type)charac.first]);
                break;
            }
        }
        _isTalking = true;
    }
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelThree::event(sf::RenderWindow &w, sf::Event &e) {
    if (e.type == sf::Event::KeyPressed) {
        if (!_walking && (e.key.code == sf::Keyboard::Right ||
        e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _isTalking = false;
            _right = e.key.code == sf::Keyboard::Right;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("walk") + (_right ? "Right" : "Left"));
        }
        if (e.key.code == sf::Keyboard::Down && !_hasTaken) {
            _take = true;
        }
        if (e.key.code == sf::Keyboard::Enter) {
            if (!_isTalking) {
                _talking = true;
            }
            _isTalking = false;
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
    for (auto &item : _objects) {
        w.draw(item.second->getSprite());
    }
    w.draw(_gameObject[CHARACTER]->getSprite());
    if (_isTalking) {
        dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->draw(w);
        dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->draw(w);
        dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->draw(w);
    }
}

void LevelThree::resume() {

}

LevelThree::LevelThree(IScene::Saves &save) : AScene(SCENE_LEVEL3, save) {
    _gameObject[MOTHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 2, _font.get(), sf::Vector2f{0, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest2");
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest3");
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
    _take = false;
    _hasTaken = false;
    _quests[MOTHER] = 0;
    _quests[FATHER] = 0;
    _quests[BROTHER] = 0;
    _objMother[0] = JOURNAL;
    _objMother[1] = GLASSES;
    _objMother[2] = VINYLE;
    _objFather[0] = HAT;
    _objFather[1] = CLOCK;
    _objFather[2] = PIPE;
    _objBrother[0] = CAR;
    _objBrother[1] = HORSE;
    _hand = NONE;
    _objects[JOURNAL] = std::make_shared<StaticGameObject>("./assets/textures/journal.png", sf::Rect{0, 0, 50, 50});
    _objects[JOURNAL]->setPosition({700, 800});
    _objects[GLASSES] = std::make_shared<StaticGameObject>("./assets/textures/glasses.png", sf::Rect{0, 0, 50, 50});
    _objects[VINYLE] = std::make_shared<StaticGameObject>("./assets/textures/vinyle.png", sf::Rect{0, 0, 50, 50});
    _objects[HAT] = std::make_shared<StaticGameObject>("./assets/textures/hat.png", sf::Rect{0, 0, 50, 50});
    _objects[CLOCK] = std::make_shared<StaticGameObject>("./assets/textures/clock.png", sf::Rect{0, 0, 50, 50});
    _objects[PIPE] = std::make_shared<StaticGameObject>("./assets/textures/pipe.png", sf::Rect{0, 0, 50, 50});
    _objects[CAR] = std::make_shared<StaticGameObject>("./assets/textures/cars.png", sf::Rect{0, 0, 50, 50});
    _objects[HORSE] = std::make_shared<StaticGameObject>("./assets/textures/horse.png", sf::Rect{0, 0, 75, 75});
    dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
}