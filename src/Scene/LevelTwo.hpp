#ifndef GGJ2020_LEVELTWO_HPP
#define GGJ2020_LEVELTWO_HPP


#include "AScene.hpp"

enum RoomType {
    TYPE_CLASSROOM,
    TYPE_CORIDOR,
    TYPE_EXIT
};

enum Room {
    NONE,
    CORIDOR_A,
    CORIDOR_B,
    CORIDOR_C,
    CLASS_1,
    CLASS_2,
    CLASS_3,
    CLASS_4,
    CLASS_5,
    CLASS_6,
    CLASS_7,
    CLASS_8,
    CLASS_9,
    CLASS_10,
    CLASS_11,
    EXIT
};

struct RoomInfoLink {
    bool opened;
    sf::Vector2f pos;
};

struct RoomInfo {
    RoomType type;
    std::string name;
    bool hasKey;
    std::pair<Room, Room> keyOpen;
    sf::Vector2f keyPos;
    std::map<Room, RoomInfoLink> links;
};

class LevelTwo : public AScene {
public:
    ~LevelTwo() override = default;
    LevelTwo(Saves &save);
    LevelTwo(LevelTwo &) = delete;
    LevelTwo &operator=(const LevelTwo &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &, sf::Shader *) override;
    void resume() override;

private:
    bool hasDoor(RoomInfo &room);
    void takeDoor(RoomInfo &room);
    void takeKey(RoomInfo &room);
    void displayRect(sf::RenderWindow &win, const sf::Color &, const sf::Vector2f &pos, const sf::Vector2f &size, sf::Shader *shader);
    void displayRoom(sf::RenderWindow &, const RoomInfo &room, sf::Shader *shader);

    std::map<Room, RoomInfo> _rooms;
    Room _actual;

    bool _right;
    bool _walking;
    bool _escape;
    int _x;
};

#endif /* GGJ2020_LEVELTWO_HPP */
