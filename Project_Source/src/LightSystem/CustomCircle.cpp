#include "LightSystem/CustomCircle.hpp"

CustomCircle::CustomCircle(unsigned definition, unsigned radius, sf::Color const& extremityColor, sf::Color const& centerColor)
    : vertices(definition + 2),
    radius(radius)
{
    unsigned pointCount = vertices.size() - 2;

    vertices[0].position = sf::Vector2f();

    for(unsigned i = 0; i < pointCount; i++)
    {
        vertices[i + 1].position = computePointPosition(i, pointCount);
    }
    vertices[pointCount + 1].position = vertices[1].position;

    updateColor(extremityColor, centerColor);
}

sf::Vector2f CustomCircle::computePointPosition(unsigned index, unsigned pointCount)
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / pointCount - pi / 2;
    float x = std::cos(angle) * radius;
    float y = std::sin(angle) * radius;

    //return sf::Vector2f(radius + x, radius + y);
    return sf::Vector2f(x, y);
}

void CustomCircle::updateColor(sf::Color const& extremityColor, sf::Color const& centerColor)
{
    vertices[0].color = centerColor;

    for(unsigned i = 1; i < vertices.size(); i++)
    {
        vertices[i].color = extremityColor;
    }
}

void CustomCircle::draw(sf::RenderTarget & target, sf::RenderStates const& states)
{
    target.draw(&vertices[0], vertices.size(), sf::TrianglesFan, states);
}

void CustomCircle::move(sf::Vector2f const& offset)
{
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        vertices[i].position += offset;
    }
}

sf::Vector2f const& CustomCircle::getPosition() const
{
    return vertices[0].position;
}

void CustomCircle::draw(sf::RenderTarget & target)
{
    target.draw(&vertices[0], vertices.size(), sf::TrianglesFan);
}