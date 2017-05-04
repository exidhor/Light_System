#include <SFML/Graphics.hpp>
#include "Movement/Movement.hpp"
#include "LightSystem/CustomCircle.hpp"
#include "LightSystem/LightPass.hpp"

void handleInput(sf::Transformable & player, sf::RenderWindow const& window, float speed, float time)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sf::Vector2f mousePositionF = sf::Vector2f(mousePosition.x, mousePosition.y);

        sf::Vector2f deplacement = Movement::deplacement(player.getPosition(), mousePositionF, speed * time);

        player.move(deplacement);
    }
}

void handleInput(CustomCircle & circle, sf::RenderWindow const& window, float speed, float time)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        //std::cout << (float)circle.getPosition().x << ", " << (float)circle.getPosition().y << std::endl;

        sf::Vector2f mousePositionF = sf::Vector2f(mousePosition.x, mousePosition.y);

        sf::Vector2f deplacement = Movement::deplacement(circle.getPosition(), mousePositionF, speed * time);

        //std::cout << deplacement.x << "; " << deplacement.y << std::endl;
        circle.move(deplacement);
    }
}

int main()
{
    sf::Shader shader;

    shader.loadFromFile("../Project_Source/src/shader/Basic.vert",
                        "../Project_Source/src/shader/NormalizedShadow.frag");

    unsigned winX = 800;
    unsigned winY = 800;

    sf::RenderWindow window(sf::VideoMode(winX, winY), "And the Light be there !");

    LightPass lightPass(window.getSize());

    sf::CircleShape wall(100.f);
    wall.setFillColor(sf::Color::Green);
    wall.setOrigin(100, 100);
    wall.setPosition(300, 300);

    sf::Color lightExtremity(0, 0, 0, 255);
    sf::Color lightCenter(255, 255, 255, 0);

    CustomCircle shape(100, 200, lightExtremity, lightCenter);

    CustomCircle fixedLight(50, 50, lightExtremity, lightCenter);
    fixedLight.move(sf::Vector2f(500, 100));

    sf::RectangleShape background(sf::Vector2f(winX, winY));
    background.setFillColor(sf::Color::Red);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        double time = elapsed.asSeconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput(shape, window, 300, (float)time);

        //light pass
        lightPass.clear();
        lightPass.drawOnTexture(shape);
        lightPass.drawOnTexture(fixedLight);
        lightPass.display();

        window.clear();
        window.draw(background);
        window.draw(wall);
        lightPass.drawRenderTexture(window);
        //shape.draw(window, shader);
        //shape.draw(window);
        window.display();
    }

    return 0;
}