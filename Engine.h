#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Heroi.h"
#include "Enemy.h"
#include "bullet.h"

class Engine {
private:
	// Add all your variables you need, your "globals".
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Vector2f viewSize;
	sf::VideoMode vm;
	sf::Sprite sprite;
	unsigned int lives;
	sf::Texture skyTexture;
	sf::Sprite skySprite;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;
	// Text
	sf::Font headingFont;
	sf::Text headingText;
	sf::Text tutorialText;
	sf::Text scoreText;
	sf::Text DefeatText;
	sf::Font font;
	// Audio
	sf::Music bgMusic;
	// ...
	//variable del personatge
	Hero Andreu;
	std::vector <Enemy*> Xaviers;

	std::vector <Bullet*> Miquelets;
	//temps entre frame
	float currentTime;
	float prevTime = 0.0f;
	//variables del joc.
	int score = 0;
	bool gameover = true;
	//funcions privades
	void reset();
	void init();
	void updateInput();
	void update(float dt);
	void draw();
	void spawnEnemy();
	void disparar();
public:
	// This is the constructor, called whenever a 'Game' object is created.
	// Use this to setup stuff you have to set once.
	// This should only be used for things that can't fail, to always have a defined state.
	Engine();
		// This is the destructor, called whenever a 'Game' object is destroyed.
	~Engine();

	// Load and run the game
	int run();
	//void updateInput();
};
