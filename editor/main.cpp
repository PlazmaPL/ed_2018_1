#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "|";
        return ss.str();
    }
};

int main()
{
    list<Ambiente> ambientes;
    list<Ambiente>::iterator iAmb;
    iAmb = --ambientes.end();



    Ambiente amb;
    amb.cursor = amb.texto.end();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                    if(event.key.control)
                        cout << "control z" << endl;
                    if(amb.cursor != amb.texto.begin() && iAmb != ambientes.begin()){
                    iAmb--;
                    ambientes.push_back(amb);
                    amb = *iAmb;
                   }
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                    if(event.key.control)
                        cout << "control r" << endl;
                    if(iAmb != ambientes.end()){
                    ambientes.push_back(amb);
                    amb = *iAmb++;
                   }
                }
                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;
                    ambientes.push_back(amb);
                    amb.texto.insert(amb.cursor,tecla);

                    iAmb = ambientes.end();
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor,' ');
                    ambientes.push_back(amb);
                    iAmb = ambientes.end();
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    if(amb.cursor != amb.texto.begin()){
                    cout << "backspace" << endl;
                    amb.texto.erase(amb.cursor++, amb.cursor--);
                    ambientes.push_back(amb);
                    iAmb = ambientes.end();
                    }
               }
                else if(event.key.code == sf::Keyboard::Delete){
                    if(amb.cursor != amb.texto.end()){
                    cout << "delete" << endl;
                    amb.texto.erase(amb.cursor++);
                    ambientes.push_back(amb);
                    iAmb = ambientes.end();
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
                else if (event.key.code == sf::Keyboard::Return){
                    cout << "enter" << endl;
                    amb.texto.insert(amb.cursor,'\n');
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}




