//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_LEVELONE_HPP
#define GGJ2020_LEVELONE_HPP


#include "AScene.hpp"
#include "../Utils/Erosion.hpp"

class LevelOne : public AScene {
public:
    LevelOne();
    LevelOne(LevelOne &) = delete;
    ~LevelOne() override = default;
    LevelOne &operator=(const LevelOne &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &,  sf::Shader *) override;
    void resume() override;

private:
    void rotateBlock(sf::RectangleShape &elem, float ratio, float maxAngle);
    void fullRotate(sf::RectangleShape &elem, float ratio);
    void moveRight();
    void moveLeft();
    void gravity();

    std::vector<s_ptr<IGameObject>> _objectCritic;
    sf::RectangleShape _bg;
    sf::Vector2f _pos;
    sf::RectangleShape _rect;
    sf::RectangleShape _back;
    bool _left;
    float _angle;
    bool _isJumping;
    sf::Vector2f _velocity;

    Erosion _erosion;
};


#endif //GGJ2020_LEVELONE_HPP
