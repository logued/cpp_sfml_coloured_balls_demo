// Sample program main.cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;


struct Ball             // same as a class
{
    int x, y;
    int moveXBy = 1; // amount to move by (here, 1 cell)
    int moveYBy = 1;
    int id;
    int cellSize;
    sf::CircleShape shape;

    // Constructor
    Ball(int id, int cellSize, sf::Color color ) {
        shape.setRadius(10);
        shape.setFillColor(color);
        x = rand() % 8;
        y = rand() % 8;
        this->id = id;
        this->cellSize = cellSize;
    }

    void move() {
        x += moveXBy;
        y += moveYBy;

        if (x >= 7 || x == 0) {
            moveXBy *= -1;
        }
        if (y >= 7 || y == 0) {
            moveYBy *= -1;
        }
        cout << id << ":" << x << " " << y << endl;
    }

    void draw(sf::RenderWindow &window) {
        shape.setPosition((x * cellSize)+15, (y * cellSize)+15); // 15 to centre the circle in the cell
        window.draw(shape);
    }
};

int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
//    sf::CircleShape shape(10.f);
//    window.setFramerateLimit(40);
//    shape.setPosition(195, 195);
//    shape.setFillColor(sf::Color::Green);
//    int moveXBy = 5;
//    int moveYBy = 5;
//    bool isGreen = true;

    vector<Ball> balls; // vector of Ball structures

    balls.push_back(Ball(1, 50, sf::Color::Cyan));
    balls.push_back(Ball(2, 50, sf::Color::Yellow));
    balls.push_back(Ball(3, 50, sf::Color::Magenta));

    int size = 8;   // width of square board (same as height)

    vector<sf::RectangleShape> board;
    bool blk = true;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            sf::RectangleShape rect(sf::Vector2f(50, 50));
            rect.setPosition(x * 50, y * 50);
            if (blk) {
                rect.setFillColor(sf::Color::Black);

            } else {
                rect.setFillColor(sf::Color::White);
            }
            blk = !blk;
            board.push_back(rect);
        }
        blk = !blk;
    }


    while (window.isOpen()) {
        sf::Event event;

        // Game loop - checks for events each time
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (Ball &b: balls) {
                        b.move();
                    }
                }

            }
            if (event.type == sf::Event::KeyReleased) {
                cout << event.key.code << endl;
                cout << sf::Keyboard::C << endl;
                if (event.key.code == sf::Keyboard::Up) {
                    for (Ball &b: balls) {
                        b.move();
                    }
                }
            }
//            if(event.type == sf::Event::MouseButtonReleased)
//            {
//                if(event.mouseButton.button == sf::Mouse::Left)
//                {
//                    if(isGreen)
//                    {
//                        shape.setFillColor(sf::Color::Red);
//                        isGreen=false;
//                    }
//                    else
//                    {
//                        shape.setFillColor(sf::Color::Green);
//                        isGreen=true;
//                    }
//                }
//            }

        }
//        shape.move(moveXBy, moveYBy);
//        if(shape.getPosition().x >=380 ||shape.getPosition().x <5 )
//        {
//            moveXBy*=-1;
//        }
//        if(shape.getPosition().y >=380 ||shape.getPosition().y <10 )
//        {
//            moveYBy*=-1;
//        }

        window.clear(sf::Color::White);
        for (sf::RectangleShape &rect: board) {
            window.draw(rect);
        }

        for (Ball &b: balls) {

            b.draw(window);
        }
        window.display();

    }

    return 0;
}
