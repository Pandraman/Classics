#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


RenderWindow window(VideoMode(1920,1080),"Renderer test");







int main() {
    


    Event ev;
    while (window.isOpen()) {
        window.clear(Color(10,10,10));




        while (window.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                window.close();
            }
        }




        window.display();
    }return 0;}