#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject {
    int lives;
    int score;

public:
    Player();
    Player(int x, int y);
    void moveLeft();
    void moveRight();
    Bullet shoot();

    void update() override;
    void render() override;

    int getLives() const;
    int getScore() const;
    void setLives(int l);
    void setScore(int s);

    Player operator+(int points);
    Player operator-(int points);
};