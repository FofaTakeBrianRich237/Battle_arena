#include "header.h"
#include <iostream>
#include <windows.h>

struct perso{
    std::string name;
    int mana = 100;
    int live = 100;
    int simple_attack;
    int renforce_simple_attack;
    int mana_renfrocement_simple_attack;
    int special_attack;
    int mana_special;
    int speed_simple;
    int speed_special;
    int defence;
    int special_defence;
    int mana_defence;
    int speed;
};
void display_live_mana(int live_or_mana)
{
   int a = live_or_mana / 10;
   int b = (a == 0) ? 9 : 10 - a;
   if(a == 0)
   {
        if(live_or_mana != 0) std::cout << "\033[31m|\033[37m";
   }
    else if(a < 4)
    {
        for(int i = 1; i <= a; i++)
        {
           std::cout << "\033[31m|\033[37m";
        }
    }
    else if(a < 7)
    {
        for(int i = 1; i <= a; i++)
        {
           std::cout << "\033[33m|\033[37m";
        }
    }
    else
    {
         for(int i = 1; i <= a; i++)
         {
           std::cout << "\033[32m|\033[37m";
         }
    }
    for(int i = 0; i < b; i++) std::cout << " ";
    std::cout << live_or_mana << "%";
}
 
void diplay1(int live1,int live2,int mana1,int mana2,perso a,perso b)
{
    std::cout << "    "<< a.name;
    std:: cout << "                                                                                                                               ";
    std::cout << b.name << std::endl << std::endl;
    std:: cout << "health" << " ";
    display_live_mana(live1);
    if (live1 == 100)std:: cout << "                                                                                                                  ";
    else if(live1 > 9) std:: cout << "                                                                                                                   ";
    else std:: cout << "                                                                                                                    ";
    std:: cout << "health" << " ";
    display_live_mana(live2);
    std:: cout << std::endl;
    std:: cout << "mana" << "   ";
    display_live_mana(mana1);
    if(mana1 == 100) std:: cout << "                                                                                                                  ";
    else if(mana1 > 9) std:: cout << "                                                                                                                   ";
    else std:: cout << "                                                                                                                    ";
    std:: cout << "mana" << "   ";
    display_live_mana(mana2);
    std::cout << std::endl;
}
void stats(perso a)
{
    std::cout << "Name: " << a.name << std::endl;
    std::cout<< "simple attack: " << a.simple_attack << std::endl;
    std::cout << "Renfroced simple attack: " << a.renforce_simple_attack - a.simple_attack << std::endl;
    std::cout << "Mana Renfroced simple attack: " << a.mana_renfrocement_simple_attack << std::endl;
    std::cout << "spcecial attack: " << a.special_attack << std::endl;
    std::cout << "mana special: " << a.mana_special << std::endl;
    std::cout << "simple attack speed: " << a.speed_simple << std::endl;
    std::cout << "special attack spedd: " << a.speed_special << std::endl;
    std::cout << "Defense: " << a.defence << std::endl;
    std::cout << "Special defence : " << a.special_defence - a.defence<< std::endl;
    std::cout << "Mana Special Defense: " << a.mana_defence << std::endl;
    std::cout << "Speed:" << a.speed << std::endl;
}
void display_grid(int board[22][118])
{
    for(int i = 0 ; i < 22; i++)
    {
        for(int j = 0; j < 118; j++)
        {
            if(board[i][j] == 0)  std::cout<< " ";
            else std:: cout << "*";
        }
        std::cout << std::endl;
    }
}
void display_actions(int board[22][118])
{
    display_grid(board);
    while(true)
    {
        attack_move(board);
        system("CLS");
        display_grid(board);
        // Sleep(150);
    }
    
}
void attack_move(int board[22][118])
{
    for(int i = 0; i < 22; i++)

    {
        for(int j = 118; j > 0; j--)
        {
            if(board[i][j] == 2)
            {
                
                if(board[i][j + 3] == 3 && j + 3  < 118)
                {
                    board[i][j + 2] = 2;
                    if(board[i][j - 1] == 0)
                    { 
                        board[i][j] = 0;
                        board[i][j + 1] = 0;
                    }
                }
                else if (board[i][j + 2] == 3 && j+ 2 < 118)
                {
                   board[i][j + 1] = 2;
                   if(board[i][j - 1] == 0)
                   { 
                        board[i][j] = 0;
                   }
                }
                else if (board[i][j + 1] == 3 && j+1 < 118) 
                {
                    board[i][j] = 0;
                }
                
                else 
                {
                    board[i][j + 3] = 2;
                    if(board[i][j - 1] == 0)
                    { 
                        board[i][j] = 0;
                        board[i][j + 1] = 0;
                        board[i][j + 2] = 0;
                   }
               }
            }
        }
    }
}