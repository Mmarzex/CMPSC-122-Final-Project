//
//  Player.cpp
//  Game
//
//  Created by Max Marze on 2/23/13.
//  Copyright (c) 2013 Max Marze. All rights reserved.
//

#include "Player.h"


void Player::CreatePlayer()
{
    playerImage.loadFromFile(resourcePath() + "Frog_one.png");
    player.setTexture(playerImage);
    player.setScale(2.f, 2.f);
    player.setPosition(400, 300);
    Speed = 10.f;
}

void Player::SpawnPlayer(sf::RenderWindow &window)
{
    window.draw(player);
}

void Player::CheckMovement(sf::RenderWindow &window)
{
    //float Speed = 10.f;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.move(Speed, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player.move(Speed * -1, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.move(0, Speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player.move(0, Speed * -1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.move(0,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.move(0, 0);
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //    player.move((Speed * -1)/2, (Speed * -1)/2);
    
}

void Player::CheckCollision(const sf::Sprite &sprite)
{
    if(player.getGlobalBounds().intersects(sprite.getGlobalBounds()) == true)
        player.move(Speed * -1, 0);
    if(player.getGlobalBounds().intersects(sprite.getGlobalBounds()) == true)
        player.move(0, Speed * -1);
}