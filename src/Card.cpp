#include"../inc/Card.hpp"

Card::Card()
{

}

Card::Card(unsigned int ID, CardType type) :
    _type(type), _ID(ID)
{
    _isUsed = false;
}

Card::~Card()
{

}

void Card::use()
{
    _isUsed = true;
}
