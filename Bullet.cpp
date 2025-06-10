#include "Bullet.h"

Bullet::Bullet() : GameObject(), direction(-1) {}
Bullet::Bullet(int x, int y, int dir, char symbol, Color color)
    : GameObject(x, y, symbol, color), direction(dir) {}

void Bullet::update() {
    y += direction;
}

void Bullet::render() {
    DrawText(&symbol, x * 10, y * 10, 20, color);
}

int Bullet::getDirection() const { return direction; }