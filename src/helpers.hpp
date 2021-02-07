#ifndef HELPERS_H
#define HELPERS_H

#include <dirent.h>

#include "pch.hpp"

extern int HEIGHT        ; 
extern int BOARD_DIAMETER; 
extern int GAP           ;
extern int STEP          ;
extern int RADIUS        ;
extern int THICK         ; 

template <typename T>
void log (T object) {
    std::cout << object << std::endl;
}

void logf (const char* format, ...);

void logColor(const sf::Color& color); 

template <typename T>
void logVector(const sf::Vector2<T>& vec) {
    std::cout << "[" << vec.x << ", " << vec.y << "]\n";
}

void loadTexture(sf::Texture* texture, const std::string& file);

void loadAllTextures(sf::Texture (&textureArray)[12]);

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code);

// template <int N>
// void drawSpriteArray(sf::RenderWindow* window, sf::Sprite* sprites) {
//     for (int i = 0; i < N; i++)
//         window->draw(sprites[i]);
// }

#endif