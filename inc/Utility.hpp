#pragma once
#include<iostream>
#include<chrono>
#include<sstream>
#include<time.h>
#include<string>
#include<iomanip>
#include<vector>
#include<functional>
#include"Card.hpp"

namespace Utility
{
    static std::string getCurrentTime(const char* format = "[%Y-%m-%d|%X]")
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), format);
        return ss.str();
    }

    static std::vector<Card> generateDefaultHand()
    {
        std::vector<Card> _hand;
        CardType currentType = CardType::Rock;
        for(int i = 0; i < 12; i++)
        {
            switch (i)
            {
            case 4: currentType = CardType::Paper;
                break;
            case 8: currentType = CardType::Scissor;
                break;
            default:
                break;
            }
            _hand.push_back(Card(i+1, currentType));
        }
        return _hand;
    }

    static std::string CardTypeToString(CardType ct)
    {
        if(ct == CardType::Rock) return "Rock";
        else if(ct == CardType::Paper) return "Paper";
        else if(ct == CardType::Scissor) return "Scissor";
        else return "UnknownCardType";
    }

    static CardType generateRandomCardType()
    {
        CardType ct;

        srand(rand());
        unsigned int x = rand()%3;

        switch (x)
        {
        case 0 : ct = CardType::Rock;
            break;
        case 1 : ct = CardType::Paper;
            break;
        case 2 : ct = CardType::Scissor;
            break;
        default: ct = CardType::Rock;
            break;
        }

        return ct;
    }

    static std::vector<Card> generateRandomHand(unsigned int n_cards)
    {
        std::vector<Card> _hand;
        srand(time(NULL));
        for(int i = 0; i < n_cards; i++)
            _hand.push_back(Card(i+1, generateRandomCardType()));
        return _hand;
    }
};