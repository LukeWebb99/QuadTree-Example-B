#include "Tools.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Point::draw(sf::RenderTarget& target, sf::Color colour, unsigned int size) {
    sf::CircleShape* dot = new sf::CircleShape(size);
    dot->setPosition(sf::Vector2f(x, y));
    dot->setOrigin(dot->getRadius() / 2, dot->getRadius() / 2);
    dot->setFillColor(colour);
    target.draw(*dot);
    delete dot;
}

Rectangle::Rectangle() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rectangle::Rectangle(float _x, float _y, float _w, float _h) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    
}

bool Rectangle::containsPoint(Point* p) {

    if  (p->x >= x - w &&
        p->x <= x + w &&
        p->y >= y - h &&
        p->y <= y + h) {
        return true;
    }
    return false;
}

bool Rectangle::Intersects(Rectangle& range) {

    return !(
        range.x - range.w > x + w ||
        range.x + range.w < x - w ||
        range.y - range.h > y + h ||
        range.y + range.h < y - h);

}