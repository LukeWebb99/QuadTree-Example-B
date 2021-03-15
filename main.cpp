#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"
#include "QuadTree.h"

int main()
{
    srand(time(0));

    Rectangle* boundary = new Rectangle(400, 400, 400, 400);
    QuadTree* qt = new QuadTree(boundary, 1);

    for (size_t i = 0; i < 500; i++) {
        Point* p = new Point(rand() % 400, rand() % 400);
        qt->Insert(p);
    }

    Rectangle* range = new Rectangle(0, 0, 50, 50);
    sf::RectangleShape rangeRect;

    rangeRect.setFillColor(sf::Color::Transparent);
    rangeRect.setOutlineThickness(1);
    rangeRect.setOutlineColor(sf::Color::Green);

    std::vector<Point*> inRange;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Quadtree");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        range->x = sf::Mouse::getPosition(window).x;
        range->y = sf::Mouse::getPosition(window).y;

        rangeRect.setPosition(range->x, range->y);
        rangeRect.setOrigin(sf::Vector2f(range->w, range->h));
        rangeRect.setSize(sf::Vector2f(range->w*2, range->h*2));

        window.clear();

        qt->Query(range, inRange);
        
        window.draw(rangeRect);
        qt->Draw(window);

        
        for (auto& p : inRange)
            p->draw(window, sf::Color::Green, 4);

        window.display();
        inRange.clear();

    }

    return 0;
}