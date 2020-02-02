//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#ifndef GGJ2020_LEVELTHREE_HPP
#define GGJ2020_LEVELTHREE_HPP


#include "AScene.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"

#define NB_OBJECT 6

class LevelThree : public AScene {
public:
    enum Type {
        MOTHER,
        FATHER,
        BROTHER,
        CHARACTER
    };

    enum ObjectType {
        JOURNAL,
        GLASSES,
        HAT,
        CLOCK,
        CAR,
        HORSE,
        VINYLE,
        PIPE,
        NONE
    };

    LevelThree(Saves &save);
    LevelThree(LevelThree &) = delete;
    ~LevelThree() override = default;
    LevelThree &operator=(const LevelThree &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &,  shaders_map &) override;
    void resume() override;

private:

    bool _walking;
    bool _right;
    sf::Vector2f _pos;
    std::map<Type, int> _quests;
    std::map<int, int> _objMother;
    std::map<int, int> _objFather;
    std::map<int, int> _objBrother;
    std::map<ObjectType, std::shared_ptr<StaticGameObject>> _objects;
    bool _talking;
    bool _isTalking;
    bool _take;
    bool _hasTaken;
    ObjectType _hand;
};


#endif //GGJ2020_LEVELTHREE_HPP
