#include "game.h"

QPair<int, int> Chase1(Enemy* enemy) {
    Morty *morty = enemy->game->morty;
    int dist_x = morty->getPosX() - enemy->getPosX();
    int dist_y = morty->getPosY() - enemy->getPosY();
    return QPair<int, int>(dist_x, dist_y);
}

QPair<int, int> Chase2(Enemy* enemy) {
    Morty *morty = enemy->game->morty;
    int dist_x = morty->getPosX() - enemy->getPosX();
    int dist_y = morty->getPosY() - enemy->getPosY();
    switch (morty->get_direction()) {
    case GameObject::Up:
        dist_y -= 4;
        break;
    case GameObject::Down:
        dist_y += 4;
        break;
    case GameObject::Left:
        dist_x -= 4;
        break;
    case GameObject::Right:
        dist_x += 4;
        break;
    default:
        break;
    }
    return QPair<int, int>(dist_x, dist_y);
}
