#include "game.h"

Game::Game(int x, int y, int m_Width, int m_Height)
{
    mapX = x;
    mapY = y;

    //Punteros para el mapa
    map_size = m_Width * m_Height;
    map_width = m_Width;
    map_height = m_Height;


}
