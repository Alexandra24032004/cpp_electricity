#include "constants.h"
#include "object.h"
#include "visual.h"
#include "project.h"
#include <SFML/Graphics.hpp>  // Подключаем заголовочный файл для работы с графикой
#include <string>
#include <iostream>


using namespace std;

void Project::run()
{
    vector<string> strings {"", "", "", "", ""};
    vector<string> inputs {"", "", "", "", ""};
    sf::Text text;
    vector<sf::Text> texts {text, text, text, text, text};
    int num_of_active_string = -1;
    bool enter_is_pressed = 0;
    
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Text Input");

    sf::Font font;  // Объявляем переменную типа шрифт
    font.loadFromFile("arial.ttf");  // Загружаем шрифт с именем "arial.ttf"

    for (int i = 0; i < strings.size(); i++) {
        texts[i].setFont(font);  // Задаем тексту шрифт который загрузили
        texts[i].setCharacterSize(24);  // Задаем размер текста (24 пикселя)
        texts[i].setFillColor(sf::Color::Black);  // Задаем цвет текста (черный)
        texts[i].setPosition(null_x, null_y + i * (width_of_bold + step));  // Задаем позицию текста на экране
    }
    

    std::string input;  // Создаем пустую строку 
    string s1 = "";
    bool flag = 0;
    while (window.isOpen())  // Бесконечный цикл, пока окно открыто
    {
        sf::Event event;  // Создаем событие
        while (window.pollEvent(event))  // Проверяем события в цикле
        {
            if (event.type == sf::Event::Closed)  // Если нажали на крестик в углу окна
            {
                window.close();  // Закрываем окно
            }
            if (event.type == sf::Event::TextEntered)  // Если вводим текст
            {
                if ((event.text.unicode < 128) && (event.text.unicode > 31))
                {
                    for (int i = 0; i < strings.size(); i++)
                    {
                        if (num_of_active_string == i)
                        {
                            inputs[i] += static_cast<char>(event.text.unicode);  // Добавляем вводимый символ в строку
                            texts[i].setString(inputs[i]);  // Обновляем строку текста с введенным символом
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if ((event.mouseButton.x <= (null_x + length_of_bold)) && (event.mouseButton.x >= null_x))
                    {
                        for (int i = 0; i < strings.size(); i++) {
                            if ((event.mouseButton.y >= null_y + (width_of_bold + step) * i) && (event.mouseButton.y <= null_y + (width_of_bold + step) * i + width_of_bold))
                            {
                                num_of_active_string = i;
                            }
                        }

                    }
                    else
                    {
                        num_of_active_string = -1;
                    }

                    if ((event.mouseButton.x > (length_of_bold + 2 * null_x)) && enter_is_pressed)
                    {
                        Object new_object(strings, event.mouseButton.x-length_of_bold - 2 * null_x, event.mouseButton.y);
                        objects.push_back(new_object);


                        visualisation(scalar_field, is_scalar, objects, window);

                        enter_is_pressed = 0;
                    }
                }

            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    num_of_active_string = -1;

                    for (int i = 0; i < strings.size(); i++) {
                        strings[i] = inputs[i];
                    }

                    enter_is_pressed = 1;

                }
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    for (int i = 0; i < strings.size(); i++)
                    {
                        if (num_of_active_string == i)
                        {
                            inputs[i] = inputs[i].substr(0, inputs[i].size() - 1);
                            texts[i].setString(inputs[i]);

                        }
                    }

                }
                if ((event.key.code == sf::Keyboard::Space) && (num_of_active_string == -1))
                {
                    //std::cout << "vec2";
                    is_scalar = !is_scalar;

                    visualisation(scalar_field, is_scalar, objects, window);

                }
            }


        }
        
        //window.clear(sf::Color::White);
        for (int i = 0; i < strings.size(); i++) {
            sf::RectangleShape rect(sf::Vector2f(500, 30));
            rect.setOutlineThickness(5);
            if (num_of_active_string == i) rect.setOutlineColor(sf::Color(255, 0, 0));
            else rect.setOutlineColor(sf::Color(150, 150, 150));
            rect.setFillColor(sf::Color(255, 255, 255));
            rect.setPosition(null_x, null_y + i * (width_of_bold + step));
            window.draw(rect);
            if (inputs[i] != "") {
                window.draw(texts[i]);
            }
            //visualisation(scalar_field, is_scalar, objects, window);
        }

        window.display();   // Обновляем экран
    
    }

    return;  
}



