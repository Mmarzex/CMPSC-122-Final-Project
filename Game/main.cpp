#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include "Player.h"

int main(int argc, const char * argv[])
{
    // Creation of window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
    
    // setting framerate limit to 60 FPS
    window.setFramerateLimit(60);
    
    window.setKeyRepeatEnabled(true);
    
    // Keeps game loop running
    //bool play = true;
    
    // Events made out side of game loop
    sf::Event event;
    
    // Event states
    
    // Movement buttons
    bool leftButton = false;
    bool rightButton = false;
    bool upButton = false;
    bool downButton = false;
    
    // Velocity for movement
    int xVelocity = 0, yVelocity = 0;
    
    // Images
    sf::Texture image1;
    if (image1.loadFromFile("/Users/maxmarze/Dropbox/sfml/Game/Game/Frog_one.png") == 0)
    {
        return 1;
    }
    
    sf::Sprite rect;
    rect.setTexture(image1);
    rect.setScale(6.f, 6.f);
    rect.setPosition(200, 200);
    
    // Render shapes
    //sf::RectangleShape rect;
    //rect.setSize(sf::Vector2f(32, 32));
    //rect.setPosition(0, 0);
    //rect.setFillColor(sf::Color::Green);
    //rect.setTexture(&image1);
    
    Player playerOne;
    playerOne.CreatePlayer();
    
    // Font
    sf::Font font;
    if(font.loadFromFile("/Users/maxmarze/Dropbox/sfml/Game/Game/Super Plumber Brothers.ttf") == 0)
    {
        return 1;
    }
    
    //Text
    sf::Text title;
    title.setFont(font);
    title.setCharacterSize(30);
    title.setString("Version .0001");
    title.setPosition(300, 50);
    title.setColor(sf::Color::Magenta);
    
    
    // Sounds
    sf::SoundBuffer ExplosionBuffer;
    if(ExplosionBuffer.loadFromFile("/Users/maxmarze/Dropbox/sfml/Game/Game/explosion.wav") == 0)
    {
        return 1;
    }
    
    sf::Sound explosion;
    explosion.setBuffer(ExplosionBuffer);
    //explosion.setLoop(true);
    //explosion.setVolume(100);
    
    explosion.play();
    // other things you can do
    //explosion.stop();
    //explosion.pause();
    
    
    // Music
    
    sf::Music titleTheme;
    if(titleTheme.openFromFile(resourcePath() + "Maxs game.ogg") == 0)
    {
        return 1;
    }
    titleTheme.setLoop(true);
    titleTheme.setVolume(50);
    titleTheme.play();
    // Game loop
    while (window.isOpen())
    {
        
        // EVENTS
        
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left)
                    leftButton = true;
                if(event.key.code == sf::Keyboard::Right)
                    rightButton = true;
                if(event.key.code == sf::Keyboard::Up)
                    upButton = true;
                if(event.key.code == sf::Keyboard::Down)
                    downButton = true;
            }
            
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Left)
                    leftButton = false;
                if(event.key.code == sf::Keyboard::Right)
                    rightButton = false;
                if(event.key.code == sf::Keyboard::Up)
                    upButton = false;
                if(event.key.code == sf::Keyboard::Down)
                    downButton = false;
            }
        }
        
        // LOGIC
        
        // Movement
        // x-axis movement
        
        if(rightButton == true)
        {
            xVelocity = 5;
        }
        
        if(leftButton == true)
        {
            xVelocity = -5;
        }
        
        if(leftButton == true && rightButton == true)
        {
            xVelocity = 0;
        }
        if(leftButton == false && rightButton == false)
        {
            xVelocity = 0;
        }
        
        // y-axis movement
        if(upButton == true)
        {
            yVelocity = -5;
        }
        
        if(downButton == true)
        {
            yVelocity = 5;
        }
        
        if(upButton == true && downButton == true)
        {
            yVelocity = 0;
        }
        
        if(upButton == false && downButton == false)
        {
            yVelocity = 0;
        }
        
        // Move
        rect.move(xVelocity, yVelocity);

        playerOne.CheckMovement(window);
        playerOne.CheckCollision(rect);
        // RENDERING

        /// Clears window
        window.clear();
        
        window.draw(rect);
        
        window.draw(title);
        
        playerOne.SpawnPlayer(window);
        
        /// Displays whatever we create
        window.display();
        
    }
    
    
    ////////
    
    // Clean up
    window.close();
    
    return 0;
}