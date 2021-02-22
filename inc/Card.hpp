#pragma once
#include<iostream>

enum class CardType
{
    Rock,
    Paper,
    Scissor
};

class Card
{
public:
    Card();
    Card(unsigned int ID, CardType type);
    ~Card();


    unsigned int ID();

    CardType type();

    void use();

    bool isUsed();

private:
    unsigned int _ID;
    CardType _type;
    bool _isUsed;
};