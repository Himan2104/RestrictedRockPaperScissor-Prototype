#include"../inc/Player.hpp"

Player::Player()
{
    Debug::log("Player created with no Name or Hand, Defaults will be used.", Debug::INFO);
    this->_name = "UnknownPlayer";
    this->_hand = Utility::generateDefaultHand();
    score = 0;
}

Player::Player(std::string name, std::vector<Card> newHand) :
    _name(name), _hand(newHand)
{
    Debug::log("Player [" + name + "] created with new Hand : [" + this->handToString() + "].", Debug::MESSAGE);
    score = 0;
}

Player::~Player()
{

}

std::string Player::name()
{
    return _name;
}

std::string Player::handToString()
{
    std::string handstr = "";
    for(auto & v: _hand)
    {
        switch (v.type())
        {
        case CardType::Rock: handstr += "R";
            break;
        case CardType::Paper: handstr += "P";
            break;
        case CardType::Scissor: handstr += "S";
            break;
        default:
            break;
        }
    }
    return handstr;
}

void Player::renewHand()
{
    _hand = Utility::generateDefaultHand();
    Debug::log("Player [" + _name + "] renewed with Hand : [" + this->handToString() + "].", Debug::MESSAGE);
}
