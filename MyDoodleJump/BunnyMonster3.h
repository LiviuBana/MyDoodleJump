#pragma once
#include "Enemy.h"
#include"BunnyMonster1.h"
class BunnyMonster3 :
    public Enemy
{
private:
    sf::Texture texture;
    sf::Sprite* sprite = new sf::Sprite();
    sf::Clock animationTimer;
    sf::IntRect currentFrame;
    float textureHeight=60;
public:
    // Inherited via Enemy
    BunnyMonster3(float xPos, float yPos);
    virtual void initAnimation() override;
    virtual void initSprite() override;
    virtual void initTexture() override;
    virtual void updateAnimation() override;
    virtual void update() override;
    virtual sf::FloatRect getBounds() const override;
    sf::Vector2f getPositions() const;
    virtual void moveDown(float x, float y) override;
    virtual void render(sf::RenderTarget* target) override;

    // Inherited via Enemy
    virtual void moveUp() override;
};

