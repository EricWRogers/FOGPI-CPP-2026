#include "Player.hpp"
#include "fogpi/io.hpp"

void Player::Start(Vec2 _pos) {
    m_character = 'P';
    m_position = _pos;

    m_keyCount = 5;
}

void Player::Update() {
    while(request_char("hit w to continue: ") != 'w') {}
}