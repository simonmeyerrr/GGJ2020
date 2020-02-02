#include "LevelTwo.hpp"
#include "../Object/GameObject/Objects/PlayerOld.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"
#include "../Object/GameObject/Objects/PlayerSchool.hpp"
#include "../Object/UIObject/Fade.hpp"

#define DOOR_HEIGHT 300
#define DOOR_WIDTH 200
#define PLAYER_HEIGHT 300
#define PLAYER_WIDTH  300
#define HEIGHT 700
#define DIFF 50



LevelTwo::LevelTwo(Saves &save)
    : AScene(SCENE_LEVEL2, save), _rooms(), _actual(CORIDOR_A), _right(true), _walking(false), _escape(false), _x(-DIFF)
{
    _rooms[CORIDOR_A] = RoomInfo{
            TYPE_CORIDOR,
            "Coridor A",
            false,
            {NONE, NONE},
            {0, 0},
            {
                    {CLASS_8, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_7, RoomInfoLink{false, {500, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_5, RoomInfoLink{false, {800, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_3, RoomInfoLink{true, {1100, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_1, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CORIDOR_B] = RoomInfo{
            TYPE_CORIDOR,
            "Coridor B",
            false,
            {NONE, NONE},
            {0, 0},
            {
                    {CLASS_6, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_7, RoomInfoLink{false, {500, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_9, RoomInfoLink{false, {800, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_10, RoomInfoLink{false, {1100, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CORIDOR_C] = RoomInfo{
            TYPE_CORIDOR,
            "Coridor C",
            false,
            {NONE, NONE},
            {0, 0},
            {
                    {CLASS_6, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_4, RoomInfoLink{false, {500, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_2, RoomInfoLink{false, {800, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_11, RoomInfoLink{false, {1100, HEIGHT - DOOR_HEIGHT}}},
                    {EXIT, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_1] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 1",
            true,
            {CLASS_5, CLASS_6},
            {750, 500},
            {
                {CORIDOR_A, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}},
                {CLASS_2, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_2] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 2",
            true,
            {CORIDOR_B, CLASS_10},
            {750, 500},
            {
                    {CLASS_1, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_3] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 3",
            true,
            {CORIDOR_A, CLASS_8},
            {750, 500},
            {
                    {CORIDOR_A, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_4, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_4] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 4",
            true,
            {CORIDOR_C, EXIT},
            {750, 500},
            {
                    {CLASS_3, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_5] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 5",
            true,
            {CLASS_7, CORIDOR_A},
            {750, 500},
            {
                    {CORIDOR_A, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_6, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_6] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 6",
            true,
            {CLASS_1, CLASS_2},
            {750, 500},
            {
                    {CLASS_5, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1000, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_C, RoomInfoLink{true, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_7] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 7",
            true,
            {CORIDOR_A, CLASS_1},
            {750, 500},
            {
                    {CORIDOR_A, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_8] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 8",
            true,
            {CORIDOR_A, CLASS_5},
            {750, 500},
            {
                    {CORIDOR_A, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CLASS_9, RoomInfoLink{false, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_9] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 9",
            true,
            {CORIDOR_C, CLASS_11},
            {750, 500},
            {
                    {CLASS_8, RoomInfoLink{false, {200, HEIGHT - DOOR_HEIGHT}}},
                    {CORIDOR_B, RoomInfoLink{true, {1400, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_10] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 10",
            true,
            {CLASS_8, CLASS_9},
            {750, 500},
            {
                    {CORIDOR_B, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[CLASS_11] = RoomInfo{
            TYPE_CLASSROOM,
            "Classroom 11",
            true,
            {CLASS_3, CLASS_4},
            {750, 500},
            {
                    {CORIDOR_C, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _rooms[EXIT] = RoomInfo{
            TYPE_CLASSROOM,
            "Exit",
            false,
            {NONE, NONE},
            {750, 500},
            {
                    {CORIDOR_C, RoomInfoLink{true, {200, HEIGHT - DOOR_HEIGHT}}}
            }
    };
    _uiObject[0] = std::make_shared<Text>("", _font.get(), sf::Vector2f{600, 800}, sf::Color::Black);
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
    _uiObject[3] = std::make_shared<Fade>();
    _gameObject[0] = std::make_shared<PlayerSchool>();
    _gameObject[0]->setPosition({static_cast<float>(_x), HEIGHT - PLAYER_HEIGHT});
    dynamic_cast<AnimatedGameObject &>(*_gameObject[0]).setCurrentAnimation("idleRight");
    hasDoor(_rooms.at(_actual));
    dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 200, false);
}

IScene::Event LevelTwo::update()
{
    _uiObject[3]->update();
    if (_escape)
        return Event{EVENT_NONE, SCENE_INTRO};
    for (const auto &object: _gameObject)
        object.second->update();
    if (_walking) {
        if (!_right && _x > -DIFF)
            _x -= 3;
        else if (_right && _x < 1600 - PLAYER_WIDTH + DIFF)
            _x += 3;
        _gameObject[0]->setPosition({static_cast<float>(_x),  HEIGHT - PLAYER_HEIGHT});
        hasDoor(_rooms.at(_actual));
    }
    if (_actual == EXIT) {
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
        }
    }
    if (e.type == sf::Event::KeyReleased) {
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
                dynamic_cast<Text &>(*_uiObject[0]).setString("Cette porte est fermee");
                return true;
            }
        }
    }
    dynamic_cast<Text &>(*_uiObject[0]).setString("");
    return false;
}

void LevelTwo::takeDoor(RoomInfo &room)
{
    for (auto &door: room.links) {
        if (door.second.pos.x <= _x + DIFF + 50 && door.second.pos.x + DOOR_WIDTH >= _x + PLAYER_WIDTH - DIFF - 50) {
            if (door.second.opened) {
                _rooms.at(door.first).links.at(_actual).opened = true;
                _x = _rooms.at(door.first).links.at(_actual).pos.x - 10;
                _gameObject[0]->setPosition({static_cast<float>(_x),  HEIGHT - PLAYER_HEIGHT});
                _actual = door.first;
            }
            return;
        }
    }
}

void LevelTwo::takeKey(RoomInfo &room)
{
    if (!room.hasKey) {
        std::cout << "no key in your room" << std::endl;
        return;
    }
    room.hasKey = false;
    std::cout << "take key, open between " << _rooms.at(room.keyOpen.first).name << " and " << _rooms.at(room.keyOpen.second).name << std::endl;
    _rooms.at(room.keyOpen.first).links.at(room.keyOpen.second).opened = true;
    _rooms.at(room.keyOpen.second).links.at(room.keyOpen.first).opened = true;
}

void LevelTwo::displayRect(sf::RenderWindow &win, const sf::Color &color, const sf::Vector2f &pos, const sf::Vector2f &size, sf::Shader *shader)
{
    sf::RectangleShape rect;

    rect.setFillColor(color);
    rect.setSize(size);
    rect.setPosition(pos);
    if (shader)
        win.draw(rect, shader);
    else
        win.draw(rect);
}

void LevelTwo::displayRoom(sf::RenderWindow &win, const RoomInfo &room, sf::Shader *shader)
{
    sf::Text text(room.name, _font.get(), 30);

    text.setFillColor(sf::Color::Black);
    displayRect(win, sf::Color::White, {0, 0}, {1600, 900}, shader);
    win.draw(text);
    for (const auto &door: room.links) {
        displayRect(win, door.second.opened ? sf::Color::Blue : sf::Color::Red, door.second.pos, {DOOR_WIDTH, DOOR_HEIGHT}, shader);
        text.setString(_rooms.at(door.first).name);
        text.setPosition(door.second.pos);
        win.draw(text);
    }
    if (room.hasKey) {
        displayRect(win, sf::Color::Magenta, room.keyPos, {50, 50}, shader);
    }
}

void LevelTwo::display(sf::RenderWindow &win, sf::Shader *shader)
{
    if (shader) {
        std::vector<sf::Glsl::Vec2> locations;
        locations.emplace_back(150, 150);
        locations.emplace_back(200, 150);

        std::vector<float> powers;
        powers.emplace_back(50);
        powers.emplace_back(130);

        std::vector<sf::Glsl::Vec4> colors;
        colors.emplace_back(0.8, 0.2, 0.1, 1);
        colors.emplace_back(0.2, 0.8, 0.1, 1);

        shader->setUniformArray("location", locations.data(), locations.size());
        shader->setUniformArray("power", powers.data(), powers.size());
        shader->setUniformArray("color", colors.data(), colors.size());
    }

    displayRoom(win, _rooms.at(_actual), shader);
    for (const auto &object: _gameObject)
        win.draw(object.second->getSprite());
    _uiObject[0]->draw(win);
    if (_escape) {
        _uiObject[1]->draw(win);
        _uiObject[2]->draw(win);
    }
    _uiObject[3]->draw(win);
}

void LevelTwo::resume()
{

}