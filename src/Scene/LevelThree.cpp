//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#include "LevelThree.hpp"
#include "../Object/GameObject/Objects/FamilyCharacter.hpp"
#include "../Object/GameObject/Objects/PlayerSchool.hpp"
#include "../Object/GameObject/Objects/PlayerKid.hpp"

#define DOOR_HEIGHT 300
#define DOOR_WIDTH 200
#define PLAYER_HEIGHT 300
#define PLAYER_WIDTH  300
#define HEIGHT 700
#define DIFF 50
#define CHARPOS _gameObject[CHARACTER]->getPosition()

IScene::Event LevelThree::update() {
    if (_quests[MOTHER] == 1/* && _quests[FATHER] == 3 && _quests[BROTHER] == 2*/) {
        _save.level3 = true;
        return {EVENT_POP_SCENE, SCENE_INTRO};
    }
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
            if (CHARPOS.x <= elem.second->getPosition().x
            && CHARPOS.x + _gameObject[CHARACTER]->getSprite().getTextureRect().width >= elem.second->getPosition().x) {
                _hand = elem.first;
                break;
            }
        }
        if (_hand != NONE) {
            _objects[_hand]->setPosition({-200, -200});
            _hasTaken = true;
        }
        _take = false;
    }
    if (_walking) {
        if (!_right && _pos.x > -DIFF)
            _pos.x -= 5;
        else if (_right && _pos.x < 1600 - PLAYER_WIDTH + DIFF)
            _pos.x += 5;
        _gameObject[CHARACTER]->setPosition(_pos);
    }
    if (_up) {
        if (CHARPOS.x + 150 >= 1322 && CHARPOS.x + 150 <= 1322 + 200 && _actualRoom > GRENIER && _goRoom) {
            _goRoom = false;
            _actualRoom = _backRoom;
            // todo: setpos
            _pos = _BackPos;
            _gameObject[CHARACTER]->setPosition(_pos);
            _gameObject[BACKGROUND]->setPosition(_RoomPos[_actualRoom]);
        }
        if (CHARPOS.x + 150 >= _upstairs[_actualRoom].x && CHARPOS.x + 150 <= _upstairs[_actualRoom].x
        + (float)(_actualRoom == ETAGE3 ? 137 : 302) && _actualRoom < GRENIER) {
            _actualRoom += 1;
            _gameObject[BACKGROUND]->setPosition({0, _gameObject[BACKGROUND]->getPosition().y + 900});
        } else {
            for (auto &elem : _doors[_actualRoom]) {
                if (CHARPOS.x + 150 >= elem.second.x && CHARPOS.x + 150 <= elem.second.x + 200 && _goRoom) {
                    _goRoom = false;
                    _backRoom = _actualRoom;
                    _actualRoom = elem.first;
                    //todo: setpos
                    std::cout << _actualRoom << std::endl;
                    _gameObject[BACKGROUND]->setPosition(_RoomPos[_actualRoom]);
                    _BackPos = _pos;
                    _pos.x = 1322;
                    _gameObject[CHARACTER]->setPosition(_pos);
                    std::cout << _gameObject[BACKGROUND]->getPosition().x << std::endl;
                    std::cout << _gameObject[BACKGROUND]->getPosition().y << std::endl;
                    break;
                }
            }
        }
        _up = false;
    } else if (_down) {
        if (CHARPOS.x + 150 >= _downstairs[_actualRoom].x && CHARPOS.x + 150 <= _downstairs[_actualRoom].x
        + (float)(_actualRoom == GRENIER ? 137 : 302) && _actualRoom != CAVE) {
            _actualRoom -= 1;
            _gameObject[BACKGROUND]->setPosition(_RoomPos[_actualRoom]);
        }
        _down = false;
    }
    if (_talking) {
        for (auto &charac : _gameObject) {
            if (dynamic_cast<FamilyCharacter *>(charac.second.get())
            && (CHARPOS.x + 100 >= charac.second->getPosition().x
            && CHARPOS.x + 100 <= charac.second->getPosition().x + charac.second->getSprite().getTextureRect().width)) {
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
        if (e.key.code == sf::Keyboard::Up) {
            _goRoom = true;
            _up = true;
        }
        if (e.key.code == sf::Keyboard::Down) {
            _down = true;
        }
        if (e.key.code == sf::Keyboard::E && !_hasTaken) {
            _take = true;
        }
        if (e.key.code == sf::Keyboard::Enter) {
            if (!_isTalking) {
                _talking = true;
            }
            _isTalking = false;
        }
        if (e.key.code == sf::Keyboard::Escape) {
            return {EVENT_POP_SCENE, SCENE_INTRO};
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        _goRoom = false;
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right))) {
            _walking = false;
            _up = false;
            _down = false;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(
                    std::string("idle") + (_right ? "Right" : "Left"));
        }
    }
    return {EVENT_NONE, SCENE_INTRO};}

void LevelThree::display(sf::RenderWindow &w, shaders_map &shaders) {
    std::vector<sf::Vector2f> locations;
    std::vector<sf::Glsl::Vec4> colors;
    std::vector<float> powers;

    shaders[AMBIENT_LIGHTS].setUniform("light_number", 1);

    if (_actualRoom == 0)
        locations.emplace_back(sf::Vector2f(795, 588));
    else if (_actualRoom == 1)
        locations.emplace_back(sf::Vector2f(1459, 445));
    else if (_actualRoom == 2)
        locations.emplace_back(sf::Vector2f(150, 462));
    else if (_actualRoom == 3)
        locations.emplace_back(sf::Vector2f(1446, 465));
    else if (_actualRoom == 4)
        locations.emplace_back(sf::Vector2f(798, 606));
    else
        locations.emplace_back(sf::Vector2f(910, 630));
    shaders[AMBIENT_LIGHTS].setUniformArray("locations", locations.data(), locations.size());

    for (int i = 0; i < 1; ++i)
        colors.emplace_back(sf::Glsl::Vec4(1.0, 0.6, 0.4, 1.0));
    shaders[AMBIENT_LIGHTS].setUniformArray("colors", colors.data(), colors.size());

    for (int i = 0; i < 1; ++i)
        powers.emplace_back(400.0);
    shaders[AMBIENT_LIGHTS].setUniformArray("powers", powers.data(), powers.size());

//    for (auto &item : _gameObject) {
//        w.draw(item.second->getSprite(), &shaders[AMBIENT_LIGHTS]);
//    }

    w.draw(_gameObject[BACKGROUND]->getSprite(), &shaders[AMBIENT_LIGHTS]);
//    for (auto &item : _objects) {
//        w.draw(item.second->getSprite());
//    }
    if (_actualRoom == ETAGE1) {
        w.draw(_gameObject[MOTHER]->getSprite(), &shaders[AMBIENT_LIGHTS]);
        if (_hand != JOURNAL || !_quests[MOTHER])
            w.draw(_objects[JOURNAL]->getSprite(), &shaders[AMBIENT_LIGHTS]);
    }
        w.draw(_gameObject[CHARACTER]->getSprite(), &shaders[AMBIENT_LIGHTS]);
    if (_isTalking) {
        dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->draw(w);
        dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->draw(w);
        dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->draw(w);
    }
}

void LevelThree::resume() {

}

LevelThree::LevelThree(IScene::Saves &save) : AScene(SCENE_LEVEL3, save) {
    _gameObject[MOTHER] = std::make_shared<FamilyCharacter>("./assets/textures/daronne.png", 3, _font.get(), sf::Vector2f{300, 840 - 300});
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("Bonjour mon petit coeur, tu peux aller\nme chercher mon journal s'il te plait?");
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest2");
    dynamic_cast<FamilyCharacter *>(_gameObject[MOTHER].get())->addQuest("quest3");
    _gameObject[FATHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 3, _font.get(), sf::Vector2f{600, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest2");
    dynamic_cast<FamilyCharacter *>(_gameObject[FATHER].get())->addQuest("quest3");
    _gameObject[BROTHER] = std::make_shared<FamilyCharacter>("./assets/textures/brother.png", 2, _font.get(), sf::Vector2f{1200, 200});
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->addQuest("quest1");
    dynamic_cast<FamilyCharacter *>(_gameObject[BROTHER].get())->addQuest("quest2");
    _gameObject[CHARACTER] = std::make_shared<PlayerKid>();
    _gameObject[CHARACTER]->setPosition({100, 840 - 300});
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
    _up = false;
    _down = false;
    _actualRoom = ETAGE1;
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
    _downstairs[GRENIER] = sf::Vector2f{177, 799};
    _upstairs[ETAGE3] = sf::Vector2f{166, 855};
    _downstairs[ETAGE3] = sf::Vector2f{1299, 824};
    _upstairs[ETAGE2] = sf::Vector2f{1299, 816};
    _downstairs[ETAGE2] = sf::Vector2f{0, 823};
    _upstairs[ETAGE1] = sf::Vector2f{0, 830};
    _downstairs[ETAGE1] = sf::Vector2f{1299, 824};
    _upstairs[CAVE] = sf::Vector2f{1299, 830};
    _gameObject[BACKGROUND] = std::make_shared<StaticGameObject>("./assets/textures/home.png", sf::Rect{0, 0, 1600, 10800});
    _gameObject[BACKGROUND]->setPosition({0, -2700});
    _doors[ETAGE3];
    _doors[ETAGE2];
    _doors[ETAGE1];
    _doors[ETAGE3][ETAGE31] = sf::Vector2f{504, 0};
    _doors[ETAGE3][ETAGE32] = sf::Vector2f{908, 0};
    _doors[ETAGE2][ETAGE21] = sf::Vector2f{381, 0};
    _doors[ETAGE2][ETAGE22] = sf::Vector2f{717, 0};
    _doors[ETAGE2][ETAGE23] = sf::Vector2f{1152, 0};
    _doors[ETAGE1][ETAGE11] = sf::Vector2f{481, 0};
    _doors[ETAGE1][ETAGE12] = sf::Vector2f{982, 0};
    _RoomPos[GRENIER] = sf::Vector2f{0, 0};
    _RoomPos[ETAGE3] = sf::Vector2f{0, -900};
    _RoomPos[ETAGE2] = sf::Vector2f{0, -1800};
    _RoomPos[ETAGE1] = sf::Vector2f{0, -2700};
    _RoomPos[CAVE] = sf::Vector2f{0, -3600};
    _RoomPos[ETAGE11] = sf::Vector2f{0, -4500};
    _RoomPos[ETAGE12] = sf::Vector2f{0, -5400};
    _RoomPos[ETAGE21] = sf::Vector2f{0, -6300};
    _RoomPos[ETAGE22] = sf::Vector2f{0, -7200};
    _RoomPos[ETAGE23] = sf::Vector2f{0, -8100};
    _RoomPos[ETAGE31] = sf::Vector2f{0, -9000};
    _RoomPos[ETAGE32] = sf::Vector2f{0, -9900};
    _goRoom = false;
}