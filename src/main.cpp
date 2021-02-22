#include<iostream>
#include"../inc/Debug.hpp"
#include"../inc/Card.hpp"
#include"../inc/Utility.hpp"
#include"../inc/Player.hpp"

unsigned int resultcalc(Card *p1, Card *p2)
{
    CardType p1ct, p2ct;
    p1ct = p1->type();
    p2ct = p2->type();

    if(p1ct == CardType::Rock)
    {
        if(p2ct == CardType::Rock) return 0;
        else if(p2ct == CardType::Paper) return 2;
        else if(p2ct == CardType::Scissor) return 1;
    }

    else if(p1ct == CardType::Paper)
    {
        if(p2ct == CardType::Rock) return 1;
        else if(p2ct == CardType::Paper) return 0;
        else if(p2ct == CardType::Scissor) return 2;
    }

    else if(p1ct == CardType::Scissor)
    {
        if(p2ct == CardType::Rock) return 2;
        else if(p2ct == CardType::Paper) return 1;
        else if(p2ct == CardType::Scissor) return 0;
    }

    return 0;
}

void run_simulation(Player* p1, Player* p2, unsigned int rounds = 100)
{

    std::ofstream graphFile("graph.txt");

    if(!graphFile.is_open()) Debug::log("graphFile not open!", Debug::ERROR);

    Debug::log("Initiating Simulation for " + std::to_string(rounds) + " rounds...", Debug::INFO);

    for(int i = 0; i < rounds; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            int p1_play, p2_play;
            do
            {
                srand(time(NULL));
                p1_play = rand()%12;
            } while (p1->_hand.at(p1_play).isUsed());

            do
            {
                srand(rand());
                p2_play = rand()%12;
            } while (p2->_hand.at(p2_play).isUsed());

            p1->_hand.at(p1_play).use();
            p2->_hand.at(p2_play).use();

            Card *p1c, *p2c;
            p1c = &p1->_hand.at(p1_play);
            p2c = &p2->_hand.at(p2_play);

            std::stringstream p1typeinfo;
            p1typeinfo << std::setw(7) << Utility::CardTypeToString(p1c->type());

            std::stringstream p2typeinfo;
            p2typeinfo << std::setw(7) << Utility::CardTypeToString(p2c->type());

            std::string CurrentPlay = "P1 : " + p1typeinfo.str() +
                                     " - P2 : " + p2typeinfo.str() + " | ";      ;

            unsigned int result = resultcalc(p1c, p2c);
            if(result == 0) 
            {
                Debug::log( CurrentPlay + "DRAW!", Debug::MESSAGE);
            }            
            else if(result == 1) 
            {
                Debug::log(CurrentPlay + "Player1 Wins!", Debug::MESSAGE);
                p1->score++;
            }
            else if(result == 2) 
            {
                Debug::log(CurrentPlay + "Player2 Wins!", Debug::MESSAGE);
                p2->score++;
            }
        }
        p1->renewHand();
        p2->renewHand();

        Debug::log(" ROUND " + std::to_string(i) + " CUMULATIVE SCORE : P1 : " + std::to_string(p1->score) 
                    + "     P2 : " + std::to_string(p2->score), Debug::INFO);

        graphFile << std::to_string(p1->score) << " " << std::to_string(p2->score) << std::endl;

    }

    graphFile.close();
}

int main()
{
    std::ofstream logfile("Debug.log");

    Debug::createLogFile(logfile);
   
    Player *p1 = new Player("Niggatello Jones", Utility::generateDefaultHand());   
    Player *p2 = new Player("Chiggatello Homes", Utility::generateDefaultHand());
    
    run_simulation(p1, p2, 69);

    logfile.close();
    return EXIT_SUCCESS;
}