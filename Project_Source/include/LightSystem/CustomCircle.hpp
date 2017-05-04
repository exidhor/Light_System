#ifndef DEF_CUSTOM_CIRCLE_HPP
#define DEF_CUSTOM_CIRCLE_HPP

#include <SFML/Graphics.hpp>

/*!
 * \class CustomCircle
 * \brief
 *
 */
class CustomCircle
{
public :
    /*!
     * \brief
     */
    CustomCircle(unsigned definition, unsigned radius, sf::Color const& extremityColor, sf::Color const& centerColor);
    
    /*!
     * \brief
     */
    //virtual ~CustomCircle();

    void draw(sf::RenderTarget & target, sf::RenderStates const& states);

    void draw(sf::RenderTarget & target);

    void move(sf::Vector2f const& offset);

    sf::Vector2f const& getPosition() const;
    
protected :

private :
    void updateColor(sf::Color const& extremityColor, sf::Color const& centerColor);
    sf::Vector2f computePointPosition(unsigned index, unsigned pointCount);

    std::vector<sf::Vertex> vertices;

    unsigned radius;
};

#endif // DEF_CUSTOM_CIRCLE_HPP
