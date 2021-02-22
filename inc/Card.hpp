#include<iostream>

enum CardType
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

    void use();

    bool isUsed();

private:
    unsigned int _ID;
    CardType _type;
    bool _isUsed;
};