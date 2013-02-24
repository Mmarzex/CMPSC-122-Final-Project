//
//  Enemy.cpp
//  Game
//
//  Created by Max Marze on 2/24/13.
//  Copyright (c) 2013 Max Marze. All rights reserved.
//

#include "Enemy.h"


void Enemy::CreateEnemy()
{
    enemyImage.loadFromFile(resourcePath() + "Snake_one.png");
    enemy.setTexture(enemyImage);
    enemy.setScale(2.f, 2.f);
    
    // Will be randomized based on player position later
    enemy.setPosition(150, 40);
    Speed = 10.f;
}

void Enemy::SpawnEnemy(sf::RenderWindow &window)
{
    window.draw(enemy);
}

// Ask UltraMax

sf::Sprite const Enemy::GetSprite()
{
    return enemy;
}