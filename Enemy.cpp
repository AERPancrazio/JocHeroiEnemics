#include "Enemy.h"
Enemy::Enemy() {

}
Enemy::~Enemy() {

}
void Enemy::init(std::string textureName,  float speed) {
	//m_position = position;
	m_speed = speed;
	// Load a Texture
	m_texture.loadFromFile(textureName.c_str());
	m_sprite.setScale(1.5, 1.5);
	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	//m_sprite.setPosition(m_position);
	srand(time(NULL));	
	m_position.x= 2024;

	int llocspawn = rand() % 5 + 1;
	if (llocspawn == 1) {
		m_position.y= 520 ;
		m_sprite.setPosition(m_position.x,
			520);
	}
	if (llocspawn == 2) {
		m_position.y = 400;

		m_sprite.setPosition(m_position.x,
			400);
	}
	if (llocspawn == 3) {
		m_position.y = 240;

		m_sprite.setPosition(m_position.x,
			240);
	}
	if (llocspawn == 4) {
		m_position.y = 300;

		m_sprite.setPosition(m_position.x,
			300);
	}
	if (llocspawn == 5) {
		m_position.y = 550;

		m_sprite.setPosition(m_position.x,
			550);
	}
	

}
void Enemy::update(float dt) {
	m_position.x -= m_speed * dt;
	m_sprite.setPosition(m_position);
}

sf::Sprite Enemy::getSprite() {
	return m_sprite;
}
