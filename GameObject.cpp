#include "GameObject.h"

GameObject::GameObject() : x(0), y(0), symbol(' '), color(WHITE) {}
GameObject::GameObject(int x, int y, char symbol, Color color) : x(x), y(y), symbol(symbol), color(color) {}
GameObject::~GameObject() {}
GameObject::GameObject(const GameObject& other) = default;
GameObject::GameObject(GameObject&& other) noexcept = default;
GameObject& GameObject::operator=(const GameObject& other) = default;
GameObject& GameObject::operator=(GameObject&& other) noexcept = default;
int GameObject::getX() const { return x; }
int GameObject::getY() const { return y; }
void GameObject::setX(int x) { this->x = x; }
void GameObject::setY(int y) { this->y = y; }
char GameObject::getSymbol() const { return symbol; }
