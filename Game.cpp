#include "Game.h"
#include "raylib.h"

Game::Game() : player(40, 55), score(0), level(1), running(true), frameCounter(0) {
    initializeEnemies();
}

Game::~Game() {
    for (auto e : enemies) delete e;
    for (auto b : bullets) delete b;
    for (auto eb : enemyBullets) delete eb;
}

void Game::initializeEnemies() {
    enemies.clear();
    for (int i = 0; i < 10; i++) {
        if (level == 1) {
            enemies.push_back(new EnemyType1(i * 5, 5));
            enemies.push_back(new EnemyType2(i * 5, 7));
        } else if (level == 2) {
            enemies.push_back(new EnemyType2(i * 5, 5));
            enemies.push_back(new EnemyType3(i * 5, 7));
        } else {
            enemies.push_back(new EnemyType3(i * 5, 5));
            enemies.push_back(new EnemyType4(i * 5, 7));
        }
    }
}

void Game::input() {
    if (IsKeyDown(KEY_LEFT)) player.moveLeft();
    if (IsKeyDown(KEY_RIGHT)) player.moveRight();
    if (IsKeyPressed(KEY_SPACE)) bullets.push_back(new Bullet(player.shoot()));
}

void Game::update() {
    frameCounter++;
    for (auto b : bullets) b->update();
    for (auto eb : enemyBullets) eb->update();
    for (auto e : enemies) e->update();

    if (frameCounter % (60 - level * 10) == 0) enemyShoot();

    checkCollisions();
    levelCheck();

    if (enemies.empty()) {
        initializeEnemies();
    }
}

void Game::enemyShoot() {
    if (!enemies.empty()) {
        int idx = GetRandomValue(0, enemies.size() - 1);
        GameObject* e = enemies[idx];
        enemyBullets.push_back(new Bullet(e->getX(), e->getY() + 1, 1, '|', RED));
    }
}

void Game::checkCollisions() {
    for (auto b = bullets.begin(); b != bullets.end();) {
        bool hit = false;
        for (auto e = enemies.begin(); e != enemies.end();) {
            if ((*b)->getX() == (*e)->getX() && (*b)->getY() == (*e)->getY()) {
                delete *e; e = enemies.erase(e);
                delete *b; b = bullets.erase(b);
                player = player + 10;
                hit = true;
                break;
            } else ++e;
        }
        if (!hit) ++b;
    }

    for (auto eb = enemyBullets.begin(); eb != enemyBullets.end();) {
        if ((*eb)->getX() == player.getX() && (*eb)->getY() == player.getY()) {
            delete *eb; eb = enemyBullets.erase(eb);
            player.setLives(player.getLives() - 1);
            if (player.getLives() <= 0) running = false;
        } else ++eb;
    }
}

void Game::levelCheck() {
    int s = player.getScore();
    if (s >= 500) level = 3;
    else if (s >= 200) level = 2;
    else level = 1;
}

void Game::render() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    // Larger player size
    DrawRectangle(player.getX() * 10, player.getY() * 10, 16, 16, GREEN);

    for (auto e : enemies) {
        Color color;
        char symbol = ((GameObject*)e)->getSymbol();
        switch (symbol) {
            case '1': color = RED; break;
            case '2': color = ORANGE; break;
            case '3': color = YELLOW; break;
            case '4': color = PURPLE; break;
            default:  color = WHITE; break;
        }
        DrawCircle(e->getX() * 10 + 8, e->getY() * 10 + 8, 8, color);
    }

    for (auto b : bullets) DrawRectangle(b->getX() * 10 + 4, b->getY() * 10, 2, 8, WHITE);
    for (auto eb : enemyBullets) DrawRectangle(eb->getX() * 10 + 4, eb->getY() * 10, 2, 8, RED);

    DrawText(TextFormat("Score: %d", player.getScore()), 10, 10, 20, WHITE);
    DrawText(TextFormat("Lives: %d", player.getLives()), 10, 30, 20, WHITE);
    DrawText(TextFormat("Level: %d", level), 10, 50, 20, WHITE);
    EndDrawing();
}

void Game::run() {
    while (!WindowShouldClose() && running) {
        input();
        update();
        render();
    }
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("GAME OVER", 300, 280, 40, RED);
    EndDrawing();
    WaitTime(3.0);
}