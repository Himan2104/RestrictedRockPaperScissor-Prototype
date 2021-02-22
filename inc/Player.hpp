#pragma once
#include"Utility.hpp"
#include"Debug.hpp"
#include"Card.hpp"
#include<vector>


class Player
{
public:
    Player();
    Player(std::string name, std::vector<Card> newHand);
    ~Player();

    std::string name();
    std::string handToString();

    std::vector<Card> _hand;

    unsigned int score;

    void renewHand();

private:
    std::string _name;
    
};