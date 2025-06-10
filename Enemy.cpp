#include "Enemy.h"

Enemy::Enemy() : GameObject(), direction(1) {}
Enemy::Enemy(int x, int y, char symbol, Color color, int direction)
    : GameObject(x, y, symbol, color), direction(direction) {}

void Enemy::update() {
    x += direction;
    if (x < 0 || x > 78) direction = -direction;
}

void Enemy::render() {
    DrawText(&symbol, x * 10, y * 10, 20, color);
}