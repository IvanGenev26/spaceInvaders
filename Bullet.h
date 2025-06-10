#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
    int direction;

public:
    Bullet();
    Bullet(int x, int y, int direction, char symbol, Color color);
    void update() override;
    void render() override;
    int getDirection() const;
};
