//
//  Enemy.h
//  Game
//
//  Created by Max Marze on 2/24/13.
//  Copyright (c) 2013 Max Marze. All rights reserved.
//

#ifndef __Game__Enemy__
#define __Game__Enemy__

#include <iostream>
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    
    void CreateEnemy();
    
    void SpawnEnemy(sf::RenderWindow &window);
    
    void CheckMovement(const sf::Sprite &player);
    
    sf::Sprite const GetSprite();
    
    bool IsDestroyable();
    
private:
    
    float Speed;
    
    sf::Sprite enemy;
    sf::Texture enemyImage;
    
    int health;
};

#endif /* defined(__Game__Enemy__) */
