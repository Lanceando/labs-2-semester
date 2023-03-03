#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>

class AnimatedText{
private:
    std::string text;
    int duration;
    int cur_duration = 0;

public:
    AnimatedText(const std::string& m_text, const int& m_duration)  {
        text = m_text;
        duration = m_duration;
    }

    std::string animtext(){
        cur_duration++;
        std::string out = text.substr(0,cur_duration);
        return out;
    }


    AnimatedText() {

    }
};



int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    std::string text = "Hello, world!";
    int duration = 13;
    int check = 0;

    AnimatedText animatedText(text, duration);

    sf::Font font;
    font.loadFromFile("C:\\Users\\ando0\\CLionProjects\\2lab1\\arial.ttf");
    sf::Text p_text;
    p_text.setColor(sf::Color::Red);
    p_text.setFont(font);
    p_text.setPosition(15,15);

    while (window.isOpen())
    {
        sf::Event event;

        for (int i = 0; i < (duration); i++)
        {
            check++;
            p_text.setString(animatedText.animtext());
            window.draw(p_text);
            window.display();
            Sleep(1000);
        }
        if(check == duration){
            Sleep(500);
            window.close();
        }


    }

    return 0;
}
