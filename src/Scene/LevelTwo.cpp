#include "LevelTwo.hpp"

#define DOOR_HEIGHT 200
#define DOOR_WIDTH 140
#define PLAYER_HEIGHT 180
#define PLAYER_WIDTH  60
#define HEIGHT 700


LevelTwo::LevelTwo()
    : AScene(SCENE_LEVEL2), _rooms(), _pos(20, HEIGHT - PLAYER_HEIGHT), _actual(CORIDOR_A)
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
}

IScene::Event LevelTwo::update()
{
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelTwo::event(sf::RenderWindow &win, sf::Event &e)
{
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Right && _pos.x < 1500)
            _pos.x += 10;
        else if (e.key.code == sf::Keyboard::Left && _pos.x > 0)
            _pos.x -= 10;
        else if (e.key.code == sf::Keyboard::Down)
            takeKey(_rooms.at(_actual));
        else if (e.key.code == sf::Keyboard::Up)
            takeDoor(_rooms.at(_actual));
    }
    return {EVENT_NONE, SCENE_INTRO};
}

void LevelTwo::takeDoor(RoomInfo &room)
{
    for (auto &door: room.links) {
        if (door.second.pos.x <= _pos.x && door.second.pos.x + DOOR_WIDTH >= _pos.x + PLAYER_WIDTH) {
            std::cout << "door found" << std::endl;
            if (door.second.opened) {
                std::cout << "go in door" << std::endl;
                _rooms.at(door.first).links.at(_actual).opened = true;
                _pos.x = _rooms.at(door.first).links.at(_actual).pos.x + 10;
                _actual = door.first;
            } else {
                std::cout << "door closed" << std::endl;
            }
            return;
        }
    }
    std::cout << "no door in front of you" << std::endl;
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
    win.draw(rect, shader);
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
    displayRect(win, sf::Color::Green, _pos, {PLAYER_WIDTH, PLAYER_HEIGHT}, shader);
}

void LevelTwo::display(sf::RenderWindow &win, sf::Shader *shader)
{
    displayRoom(win, _rooms.at(_actual), shader);
}

void LevelTwo::resume()
{

}