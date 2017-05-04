#ifndef DEF_LIGHT_PASS_HPP
#define DEF_LIGHT_PASS_HPP

#include <SFML/Graphics.hpp>
#include "LightSystem/CustomCircle.hpp"

/*!
 * \class LightPass
 * \brief
 *
 */
class LightPass
{
public :
    /*!
     * \brief
     */
    LightPass(sf::Vector2u const& size);

    void clear();

    void drawOnTexture(const sf::Vertex* vertices,
                       std::size_t vertexCount,
                       sf::PrimitiveType type,
                       sf::RenderStates const& states = sf::RenderStates() );

    void drawOnTexture(CustomCircle & customCircle);

    void display();

    void drawRenderTexture(sf::RenderTarget & target);


protected :

private :

    sf::BlendMode blendMode;
    sf::Shader lightShader;
    sf::RenderTexture lightTexture;
};

#endif // DEF_LIGHT_PASS_HPP
