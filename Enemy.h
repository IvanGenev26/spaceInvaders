#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
protected:
    int direction;

public:
    Enemy();
    Enemy(int x, int y, char symbol, Color color, int direction);
    void update() override;
    void render() override;
};
