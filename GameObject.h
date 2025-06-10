#pragma once
#include "raylib.h"

class GameObject {
protected:
    int x, y;
    char symbol;
    Color color;

public:
    GameObject();
    GameObject(int x, int y, char symbol, Color color);
    virtual ~GameObject();
    GameObject(const GameObject& other);
    GameObject(GameObject&& other) noexcept;
    GameObject& operator=(const GameObject& other);
    GameObject& operator=(GameObject&& other) noexcept;

    virtual void update() = 0;
    virtual void render() = 0;

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    char getSymbol() const;
};