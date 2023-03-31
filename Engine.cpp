#include "Engine.h"
#include "Heroi.h"
#include <sstream>
// This is the constructor, called whenever a 'Game' object is init.
Engine::Engine() {
	// Get the screen resolution and create an SFML window and View
	//mides de la finestra
	viewSize.x = 1128;
	viewSize.y = 688;
	//construïm la finestra de joc.
	window.create(sf::VideoMode(viewSize.x, viewSize.y),
		"Joc heroi - enemic",
		sf::Style::Default);
}
// This is the destructor, called whenever a 'Game' object is destroyed.
Engine::~Engine() {
}
// Load and run the game
int Engine::run() {
	sf::Clock clock;
	init();
	while (window.isOpen()) {
		updateInput();
		sf::Time dt = clock.restart();
		if (!gameover) {
			update(dt.asSeconds());
		}
		draw();
	}
	return 0;
}
void Engine::init() {
	//carregam les imatges del fons
	skyTexture.loadFromFile("Assets/graphics/fondo.png");
	skySprite.setTexture(skyTexture);
	skySprite.setScale(4, 2);
	
	bgSprite.setTexture(bgTexture);
	// Load font
	headingFont.loadFromFile("Assets/fonts/SnackerComic.ttf");
	//scoreFont.loadFromFile("Assets/fonts/arial.ttf");
	// Set Heading Text
	headingText.setFont(headingFont);
	headingText.setString("Tiny Bazooka");
	headingText.setCharacterSize(84);
	headingText.setFillColor(sf::Color::Red);
	sf::FloatRect headingbounds = headingText.getLocalBounds();
	headingText.setOrigin(headingbounds.width / 2, headingbounds.height / 2);
	headingText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));
	// Set Score Text
	// Tutorial Text
	tutorialText.setFont(headingFont);
	tutorialText.setString("Press Down Arrow to Fire and Start Game, Up Arrow to Jump");
	tutorialText.setCharacterSize(35);
	tutorialText.setFillColor(sf::Color::Red);
	sf::FloatRect tutorialbounds = tutorialText.getLocalBounds();
	tutorialText.setOrigin(tutorialbounds.width / 2, tutorialbounds.height / 2);
	tutorialText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.20f));
	// Audio
	bgMusic.openFromFile("Assets/audio/elnano.ogg");
	bgMusic.play();
	//inicialitzem el jugador
	Andreu.init("Assets/graphics/hero2.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
	srand((int)time(0));

	
	
}
void Engine::updateInput() {
	//scoreText
		font.loadFromFile("fonts/KOMIKAP_.ttf");
		scoreText.setFont(font);
		scoreText.setCharacterSize(50);
		scoreText.setPosition(20, 20);

		DefeatText.setFont(font);
		DefeatText.setCharacterSize(100);
		DefeatText.setString("Defeat");
		DefeatText.setPosition(340, 1012);

	sf::Event event;
	// while there are pending events...
	 while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) { //revisem les tecles premudes
			if (event.key.code == sf::Keyboard::Right) {//personatge dispara
				disparar();
			}
			if (event.key.code == sf::Keyboard::Up) {//personatge sala
				Andreu.jump(750.0f);
			}
			if (event.key.code == sf::Keyboard::Down) {
				if (gameover) {//si no joguem llavors engeguem el joc.
					gameover = false;
					reset();
				}
			}
		
		}
		// Update the score text
		std::stringstream ss;
		ss << "Score = " << score;
		scoreText.setString(ss.str());
		//condicions per tancar el programa
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		window.close();
	}
}

void Engine::spawnEnemy() {
	int spriteenemic;
	Enemy* enemy = new Enemy();
	spriteenemic = 1+ rand()%3;
	if (spriteenemic == 1) {
		enemy->init("Assets/graphics/enemy1.png", 200);
	}
	else if(spriteenemic == 2) {
		enemy->init("Assets/graphics/enemy2.png", 200);
	}
	else if(spriteenemic == 3) {
		enemy->init("Assets/graphics/enemy3.png", 200);
	}
	//inicialitzem els nombre aleatoris.
	
	Xaviers.push_back(enemy);

}
void Engine::update(float dt) {
	//actualitzem la posició del personatg
	Andreu.update(dt);
	//modifiquem el temps per sabre el que ha passat
	currentTime += dt;
	// Spawn Enemies
	if (currentTime > prevTime + 2)
	{
		spawnEnemy();
		prevTime = currentTime;
	}

	// Update Enemies
	for (unsigned int i = 0; i < Xaviers.size(); ++i)
	{
		Xaviers[i]->update(dt);
		if (Xaviers[i]->getSprite().getPosition().x <= 0) {
			gameover = true;
		}
	}


	// Update rockets
	for (unsigned int i = 0; i < Miquelets.size(); ++i)
	{
		Miquelets[i]->update(dt);
	}
	// Check collision between Rocket and Enemies
	for (unsigned int j = 0; j < Xaviers.size(); ++j)
	{
		for (unsigned int i = 0; i < Miquelets.size(); ++i)
		{

			if (Xaviers[j]->getSprite().getGlobalBounds().intersects(Miquelets[i]->getSprite().getGlobalBounds())) {


				delete(Miquelets[i]);
				delete(Xaviers[j]);
				Miquelets.erase(Miquelets.begin() + i);
				Xaviers.erase(Xaviers.begin() + j);		
				score = score + 1;
			}	
		}
	}
	// Check collision between Rocket and Enemies
}
void Engine::draw(){
	// netejem la pantalla
	window.clear(sf::Color::Red);
	//dibuixem elements
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(Andreu.getSprite());
	window.draw(scoreText);
	for (Bullet* b : Miquelets) {
		window.draw(b->getSprite());
	}
	for (Enemy* e : Xaviers) {
		window.draw(e->getSprite());
	}
	//mostrem text depenent si estem jugant o no
	if (gameover) {
		window.draw(headingText);
		window.draw(tutorialText);
	}
	else {
		//window.draw(scoreText);
	}
	//enviem a la pantalla.
	window.display();
}

void Engine::reset() {
	score = 0;
	currentTime = 0.0f;
	prevTime = 0.0;
	//scoreText.setString("Score: 0");
}

void Engine::disparar() {
	
	Bullet* vala = new Bullet();
	vala->init("Assets/graphics/rocket.png", Andreu.getSprite().getPosition(), -800);
	//inicialitzem els nombre aleatoris.

	Miquelets.push_back(vala);
}