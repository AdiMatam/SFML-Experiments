#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"

struct Slot : public sf::CircleShape {
    static sf::Color* fill;
    static std::vector<sf::Color>* colors;
    enum ColorIndex {
        TOP, TOP_RIGHT, TOP_LEFT, BOTTOM, BOTTOM_RIGHT, BOTTOM_LEFT
    };
    sf::CircleShape overlay;

    Slot() = default;
    Slot(float x, float y, int row);
    ~Slot() = default;

    bool clicked(float mouseX, float mouseY) const;
    void pick();
    void resetFill();

private:
    void determineColor(float x, float y, int row);
    void setup();
};

#endif