#include "Player.h"

Player::Player() : GameObject(), lives(3), score(0) {}
Player::Player(int x, int y) : GameObject(x, y, '^', GREEN), lives(3), score(0) {}

void Player::moveLeft() { if (x > 0) x--; }
void Player::moveRight() { if (x < 78) x++; }

Bullet Player::shoot() {
    return Bullet(x, y - 1, -1, '|', WHITE);
}

void Player::update() {}

void Player::render() {
    DrawText(&symbol, x * 10, y * 10, 20, color);
}

int Player::getLives() const { return lives; }
int Player::getScore() const { return score; }
void Player::setLives(int l) { lives = l; }
void Player::setScore(int s) { score = s; }

Player Player::operator+(int points) {
    score += points;
    return *this;
}

Player Player::operator-(int points) {
    score -= points;
    return *this;
}