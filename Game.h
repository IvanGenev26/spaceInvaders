#pragma once
#include <vector>
#include "Player.h"
#include "EnemyTypes.h"
#include "Bullet.h"

class Game {
    Player player;
    std::vector<GameObject*> enemies;
    std::vector<GameObject*> bullets;
    std::vector<GameObject*> enemyBullets;
    int score;
    int level;
    bool running;
    int frameCounter;

    void initializeEnemies();
    void input();
    void update();
    void checkCollisions();
    void render();
    void levelCheck();
    void enemyShoot();

public:
    Game();
    ~Game();
    void run();
};
