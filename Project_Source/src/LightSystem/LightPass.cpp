#include "LightSystem/LightPass.hpp"

LightPass::LightPass(sf::Vector2u const& size)
    : blendMode(sf::BlendMode::Factor::OneMinusDstColor,
                sf::BlendMode::Factor::One,
                sf::BlendMode::Equation::Add,
                sf::BlendMode::Factor::One,
                sf::BlendMode::Factor::One,
                sf::BlendMode::Equation::Add)
{
    lightTexture.create(size.x, size.y);

    lightShader.loadFromFile("../Project_Source/src/shader/Basic.vert",
                             "../Project_Source/src/shader/NormalizedShadow.frag");
}

void LightPass::clear()
{
    lightTexture.clear();
}

void LightPass::drawOnTexture(const sf::Vertex* vertices,
                              std::size_t vertexCount,
                              sf::PrimitiveType type,
                              sf::RenderStates const& states)
{
    sf::RenderStates newState(blendMode, states.transform, states.texture, states.shader);

    lightTexture.draw(vertices, vertexCount, type, newState);
}

void LightPass::drawOnTexture(CustomCircle & customCircle)
{
    sf::RenderStates newState(blendMode);

    customCircle.draw(lightTexture, newState);
}

void LightPass::drawRenderTexture(sf::RenderTarget & target)
{
    sf::Sprite render(lightTexture.getTexture());
    target.draw(render);
}

void LightPass::display()
{
    lightTexture.display();
}