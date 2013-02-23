//
//  Player.h
//  Game
//
//  Created by Max Marze on 2/23/13.
//  Copyright (c) 2013 Max Marze. All rights reserved.
//

#ifndef __Game__Player__
#define __Game__Player__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Player
{
public:
    
    void CreatePlayer();
    
    void SpawnPlayer(sf::RenderWindow &window);
    
    void CheckMovement(sf::RenderWindow &window);
    
private:
    
    sf::Texture playerImage;
    sf::Sprite player;
};

#endif /* defined(__Game__Player__) */
