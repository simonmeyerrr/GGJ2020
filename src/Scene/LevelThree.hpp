//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#ifndef GGJ2020_LEVELTHREE_HPP
#define GGJ2020_LEVELTHREE_HPP


#include "AScene.hpp"

class LevelThree : public AScene {
public:
    enum Type {
        MOTHER,
        FATHER,
        BROTHER,
        CHARACTER
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
    int _motherQuest;
    int _fatherQuest;
    int _brotherQuest;
    std::map<Type, int> _quests;
    bool _talking;
};


#endif //GGJ2020_LEVELTHREE_HPP
