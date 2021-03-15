#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

struct Point {
    Point();
    Point(float _x, float _y);

    void draw(sf::RenderTarget& target, sf::Color colour, unsigned int size);

    float x, y;
};

struct Rectangle {

    Rectangle();
    Rectangle(float _x, float _y, float _w, float _h);

    bool containsPoint(Point* p);
    bool Intersects(Rectangle& range);

    float x, y, w, h;
};
