#include "LevelTwo.hpp"
#include "../Object/GameObject/Objects/PlayerOld.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"
#include "../Object/GameObject/Objects/PlayerSchool.hpp"
#include "../Object/UIObject/Fade.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"
#include "../Object/UIObject/TippingText.hpp"

#define DOOR_HEIGHT 300
#define DOOR_WIDTH 200
#define PLAYER_HEIGHT 260
#define PLAYER_WIDTH  300
#define HEIGHT 790
#define DIFF 50



LevelTwo::LevelTwo(Saves &save)
    : AScene(SCENE_LEVEL2, save), _rooms(), _actual(CORIDOR_A), _right(true), _walking(false), _escape(false), _x(-DIFF)
{
    _rooms[CORIDOR_A] = RoomInfo{
            TYPE_CORIDOR,
            "Couloir A",
            false,
            {NONE, NONE},
            {
                    {CLASS_8, RoomInfoLink{false, {100, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_7, RoomInfoLink{false, {400, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_5, RoomInfoLink{false, {700, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_3, RoomInfoLink{true, {1000, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_1, RoomInfoLink{false, {1300, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CORIDOR_B] = RoomInfo{
            TYPE_CORIDOR,
            "Couloir B",
            false,
            {NONE, NONE},
            {
                    {CLASS_6, RoomInfoLink{false, {160, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_7, RoomInfoLink{false, {520, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_9, RoomInfoLink{false, {880, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_10, RoomInfoLink{false, {1240, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CORIDOR_C] = RoomInfo{
            TYPE_CORIDOR,
            "Couloir C",
            false,
            {NONE, NONE},
            {
                    {CLASS_6, RoomInfoLink{false, {100, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_4, RoomInfoLink{false, {400, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_2, RoomInfoLink{false, {700, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_11, RoomInfoLink{false, {1000, HEIGHT - DOOR_HEIGHT}}},
                    {EXIT, RoomInfoLink{false, {1300, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_1] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 1",
            true,
            {CLASS_5, CLASS_6},
            {
                {CORIDOR_A, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}},
                {CLASS_2, RoomInfoLink{false, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_2] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 2",
            true,
            {CORIDOR_B, CLASS_10},
            {
                    {CLASS_1, RoomInfoLink{false, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_3] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 3",
            true,
            {CORIDOR_A, CLASS_8},
            {
                    {CORIDOR_A, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_4, RoomInfoLink{false, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_4] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 4",
            true,
            {CORIDOR_C, EXIT},
            {
                    {CLASS_3, RoomInfoLink{false, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_5] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 5",
            true,
            {CLASS_7, CORIDOR_A},
            {
                    {CORIDOR_A, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_6, RoomInfoLink{false, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_6] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 6",
            true,
            {CLASS_1, CLASS_2},
            {
                    {CLASS_5, RoomInfoLink{false, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1145, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1375, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_7] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 7",
            true,
            {CORIDOR_A, CLASS_1},
            {
                    {CORIDOR_A, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_8] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 8",
            true,
            {CORIDOR_A, CLASS_5},
            {
                    {CORIDOR_A, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_9, RoomInfoLink{false, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_9] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 9",
            true,
            {CORIDOR_C, CLASS_11},
            {
                    {CLASS_8, RoomInfoLink{false, {140, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1260, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_10] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 10",
            true,
            {CLASS_8, CLASS_9},
            {
                    {CORIDOR_B, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_11] = RoomInfo{
            TYPE_CLASSROOM,
            "Classe 11",
            true,
            {CLASS_3, CLASS_4},
            {
                    {CORIDOR_C, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[EXIT] = RoomInfo{
            TYPE_EXIT,
            "Sortie",
            false,
            {NONE, NONE},
            {
                    {CORIDOR_C, RoomInfoLink{true, {140, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _uiObject[0] = std::make_shared<Text>("", _font.get(), sf::Vector2f{600, 800}, sf::Color::White);
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
    _uiObject[3] = std::make_shared<Fade>();
    _uiObject[4] = std::make_shared<TippingText>(_font.get());
    _gameObject[0] = std::make_shared<PlayerSchool>();
    _gameObject[0]->setPosition({static_cast<float>(_x), HEIGHT - PLAYER_HEIGHT});
    _gameObject[1] = std::make_shared<StaticGameObject>("./assets/textures/classroom.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[2] = std::make_shared<StaticGameObject>("./assets/textures/coridor.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[3] = std::make_shared<StaticGameObject>("./assets/textures/door_open.png", sf::IntRect{0, 0, 200, 300});
    _gameObject[4] = std::make_shared<StaticGameObject>("./assets/textures/door_close.png", sf::IntRect{0, 0, 200, 300});
    _gameObject[5] = std::make_shared<StaticGameObject>("./assets/textures/key.png", sf::IntRect{0, 0, 50, 50});
    _gameObject[5]->setPosition({775, 600});
    _gameObject[6] = std::make_shared<StaticGameObject>("./assets/textures/exit.png", sf::IntRect{0, 0, 1600, 900});
    _sounds[DOOR] = std::make_shared<SoundObject>("./assets/sound/scene2/door_open.ogg");
    _sounds[KEYS] = std::make_shared<SoundObject>("./assets/sound/scene2/keys_pickup.ogg");
    _sounds[LOCKED] = std::make_shared<SoundObject>("./assets/sound/scene2/locked_door.ogg");
    _sounds[DRING] = std::make_shared<SoundObject>("./assets/sound/scene2/dring.ogg");
    _sounds[DRING]->setVolume(40);
    _sounds[SUCCEED] = std::make_shared<SoundObject>("./assets/sound/common/success.ogg");
    _music = std::make_shared<MusicObject>("./assets/sound/scene2/stress_theme.ogg");
    _music->setLoop(true);
    _music->play();
    dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation("idleRight");
    hasDoor(_rooms.at(_actual));
    _sounds[DRING]->play();
    dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 200, false);
}

IScene::Event LevelTwo::update()
{
    _uiObject[3]->update();
    if (_escape)
        return Event{EVENT_NONE, SCENE_INTRO};
    for (const auto &object: _gameObject)
        object.second->update();
    _uiObject[4]->update();
    if (dynamic_cast<TippingText &>(*_uiObject[4]).getState() != TippingText::CLEAN)
        return Event{EVENT_NONE, SCENE_INTRO};
    if (_walking) {
        if (!_right && _x > -DIFF)
            _x -= 5;
        else if (_right && _x < 1600 - PLAYER_WIDTH + DIFF)
            _x += 5;
        _gameObject[0]->setPosition({static_cast<float>(_x),  HEIGHT - PLAYER_HEIGHT});
        hasDoor(_rooms.at(_actual));
    }
    if (_actual == EXIT && _x > 1000) {
        _save.level2 = true;
        return {EVENT_POP_SCENE, SCENE_INTRO};
    }
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelTwo::event(sf::RenderWindow &win, sf::Event &e)
{
    if (_escape) {
        if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Enter)
            return Event{EVENT_POP_SCENE, SCENE_INTRO};
        else if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Escape)
            _escape = false;
        return Event{EVENT_NONE, SCENE_INTRO};
    }
    if (dynamic_cast<TippingText &>(*_uiObject[4]).getState() != TippingText::CLEAN) {
        if (dynamic_cast<TippingText &>(*_uiObject[4]).getState() == TippingText::ENDED && e.type == sf::Event::KeyPressed)
            dynamic_cast<TippingText &>(*_uiObject[4]).clean();
        return Event{EVENT_NONE, SCENE_INTRO};
    }
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            _escape = !_escape;
        } else if (!_walking && (e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("walk") + (_right ? "Right" : "Left"));
        } else if (e.key.code == sf::Keyboard::Up) {
            takeDoor(_rooms.at(_actual));
        } else if (e.key.code == sf::Keyboard::Down) {
            takeKey(_rooms.at(_actual));
        } else if (e.key.code == sf::Keyboard::P) {
            _x = 0;
            _actual = EXIT;
            _sounds[SUCCEED]->play();
            _walking = true;
            _right = true;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("walk") +  "Right");
            dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 500, true);
        }
    }
    if (e.type == sf::Event::KeyReleased && _actual != EXIT) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right))) {
            _walking = false;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
        }
    }
    return Event{EVENT_NONE, SCENE_INTRO};
}

bool LevelTwo::hasDoor(RoomInfo &room)
{
    for (auto &door: room.links) {
        if (door.second.pos.x <= _x + DIFF + 50 && door.second.pos.x + DOOR_WIDTH >= _x + PLAYER_WIDTH - DIFF - 50) {
            if (door.second.opened) {
                dynamic_cast<Text &>(*_uiObject[0]).setString("Fleche du haut pour entrer dans cette salle");
                return true;
            } else {
                dynamic_cast<Text &>(*_uiObject[0]).setString("");
                return true;
            }
        }
    }
    if (!room.hasKey || _x > 750 || _x < 550) {
        dynamic_cast<Text &>(*_uiObject[0]).setString("");
    } else {
        dynamic_cast<Text &>(*_uiObject[0]).setString("Fleche du bas pour prendre la cle");
    }
    return false;
}

void LevelTwo::takeDoor(RoomInfo &room)
{
    for (auto &door: room.links) {
        if (door.second.pos.x <= _x + DIFF + 50 && door.second.pos.x + DOOR_WIDTH >= _x + PLAYER_WIDTH - DIFF - 50) {
            if (door.second.opened) {
                _sounds[DOOR]->play();
                _rooms.at(door.first).links.at(_actual).opened = true;
                _x = _rooms.at(door.first).links.at(_actual).pos.x - 30;
                _gameObject[0]->setPosition({static_cast<float>(_x),  HEIGHT - PLAYER_HEIGHT});
                _actual = door.first;
                if (_rooms.at(_actual).type == TYPE_CORIDOR) {
                    std::string phrases[] = {
                        "Tu sers a rien !",
                        "T'es insignifiant ...",
                        "T'apporteras jamais rien a la societe.",
                        "T'es adopte, pauvre con !",
                        "Donne moi ton gouter !"
                    };
                    dynamic_cast<TippingText &>(*_uiObject[4]).start(phrases[std::rand() % 5]);
                    _walking = false;
                    dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
                }
                if (_actual == EXIT) {
                    _sounds[SUCCEED]->play();
                    _walking = true;
                    _right = true;
                    dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("walk") +  "Right");
                    dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 500, true);
                }
            } else {
                _sounds[LOCKED]->play();
            }
            return;
        }
    }
}

void LevelTwo::takeKey(RoomInfo &room)
{
    if (!room.hasKey || _x > 750 || _x < 550) {
        return;
    }
    _walking = false;
    room.hasKey = false;
    dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
    _sounds[KEYS]->play();
    _rooms.at(room.keyOpen.first).links.at(room.keyOpen.second).opened = true;
    _rooms.at(room.keyOpen.second).links.at(room.keyOpen.first).opened = true;
    dynamic_cast<TippingText &>(*_uiObject[4]).start("               Ces cles ouvrent la porte entre\n                         " + _rooms.at(room.keyOpen.first).name + " et " + _rooms.at(room.keyOpen.second).name);
}

void LevelTwo::displayRoom(sf::RenderWindow &win, const RoomInfo &room, shaders_map &shaders)
{
    sf::Text text(room.name, _font.get(), 30);

    win.draw(_gameObject[room.type == TYPE_CLASSROOM ? 1 : room.type == TYPE_CORIDOR ? 2 : 6]->getSprite(), &shaders[AMBIENT_LIGHTS]);
    text.setFillColor(sf::Color::White);
    for (const auto &door: room.links) {
        int nb = door.second.opened ? 4 : 3;
        _gameObject[nb]->setPosition(door.second.pos);
        win.draw(_gameObject[nb]->getSprite(), &shaders[AMBIENT_LIGHTS]);
        text.setString(_rooms.at(door.first).name);
        text.setPosition({door.second.pos.x + 50, door.second.pos.y - 50});
        win.draw(text, &shaders[AMBIENT_LIGHTS]);
    }
    if (room.hasKey)
        win.draw(_gameObject[5]->getSprite(), &shaders[AMBIENT_LIGHTS]);
}

void LevelTwo::display(sf::RenderWindow &win, shaders_map &shaders)
{
    std::vector<sf::Vector2f> locations;
    std::vector<sf::Glsl::Vec4> colors;
    std::vector<float> powers;

    if (_rooms.at(_actual).type == RoomType::TYPE_CLASSROOM) {
        shaders[AMBIENT_LIGHTS].setUniform("light_number", 1);

        locations.emplace_back(sf::Vector2f(785, 680));
        shaders[AMBIENT_LIGHTS].setUniformArray("locations", locations.data(), locations.size());

        for (int i = 0; i < 1; ++i)
            colors.emplace_back(sf::Glsl::Vec4(1.0, 0.6, 0.4, 1.0));
        shaders[AMBIENT_LIGHTS].setUniformArray("colors", colors.data(), colors.size());

        for (int i = 0; i < 1; ++i)
            powers.emplace_back(600.0);
        shaders[AMBIENT_LIGHTS].setUniformArray("powers", powers.data(), powers.size());
    } else {
        shaders[AMBIENT_LIGHTS].setUniform("light_number", 5);

        for (int i = 0; i < 5; ++i) {
            if (_rooms.at(_actual).type == RoomType::TYPE_CORIDOR)
                locations.emplace_back(sf::Vector2f(400 * i, 900));
            else
                locations.emplace_back(sf::Vector2f(400 * i, 1200));
        }
        shaders[AMBIENT_LIGHTS].setUniformArray("locations", locations.data(), locations.size());

        for (int i = 0; i < 5; ++i)
            colors.emplace_back(sf::Glsl::Vec4(1.0, 1.0, 1.0, 1.0));
        shaders[AMBIENT_LIGHTS].setUniformArray("colors", colors.data(), colors.size());

        for (int i = 0; i < 5; ++i) {
            if (_rooms.at(_actual).type == RoomType::TYPE_CORIDOR)
                powers.emplace_back(150.0);
            else
                powers.emplace_back(200.0);
            shaders[AMBIENT_LIGHTS].setUniformArray("powers", powers.data(), powers.size());
        }
    }

    displayRoom(win, _rooms.at(_actual), shaders);
    win.draw(_gameObject[0]->getSprite(), &shaders[AMBIENT_LIGHTS]);
    _uiObject[0]->draw(win);
    _uiObject[4]->draw(win);
    if (_escape) {
        _uiObject[1]->draw(win);
        _uiObject[2]->draw(win);
    }
    _uiObject[3]->draw(win);
}

void LevelTwo::resume()
{

}