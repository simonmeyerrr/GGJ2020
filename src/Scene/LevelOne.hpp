//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_LEVELONE_HPP
#define GGJ2020_LEVELONE_HPP


#include "AScene.hpp"

class LevelOne : public AScene {
    enum Type {
        BACKGROUND,
        CHARACTER
    };
    enum Sounds {
        FOREST,
        JUMP_END,
        STEPS,
        WATER
    };
public:
    LevelOne(Saves &save);
    LevelOne(LevelOne &) = delete;
    ~LevelOne() override = default;
    LevelOne &operator=(const LevelOne &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &,  shaders_map &) override;
    void resume() override;

private:
    void rotateBlock(sf::RectangleShape &elem, float ratio, float maxAngle);
    void fullRotate(sf::RectangleShape &elem, float ratio);
    void moveRight();
    void moveLeft();
    void gravity();
    void move();

    sf::RectangleShape _bg;
    sf::Vector2f _pos;
    bool _left;
    float _angle;
    bool _isJumping;
    bool _right;
    bool _walking;
    sf::Vector2f _velocity;
    bool _escape;
};


#endif //GGJ2020_LEVELONE_HPP
