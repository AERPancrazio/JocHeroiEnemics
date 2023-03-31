//bullet enemy = new bullet;
#include "bullet.h"
Bullet::Bullet() {

}
Bullet::~Bullet() {

}
void Bullet::init(std::string textureName, sf::Vector2f position, float speed) {
	m_position = position;
	m_speed = speed;
	// Load a Texture
	m_texture.loadFromFile(textureName.c_str());
	m_sprite.setScale(0.075, 0.075);
	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	//m_sprite.setPosition(m_position);
	m_sprite.setPosition(m_position);




}
void Bullet::update(float dt) {
	m_position.x -= m_speed * dt;
	m_sprite.setPosition(m_position);
}

sf::Sprite Bullet::getSprite() {
	return m_sprite;
}
