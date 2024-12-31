#include <iostream> 
#include "header.h"
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
int board [22][118] = 
{
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,3},
    {3,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,1,1,1,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,2,0,2,2,2,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,1,0,1,0,1,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,2,0,2,2,2,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,3},
    {3,0,0,0,0,1,0,0,1,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,3},
    {3,0,0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,3},
    {3,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,3},
    {3,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,3},
    {3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,3},
    {3,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
};
void game(perso d1,perso d2);
int main()
{
    display_actions(board);
    
    perso a,b,c,d1,d2;
    perso * d11 = &d1;
    perso* d22 = &d2;
    a.name = "alonzo";
    a.simple_attack = 3;
    a.special_attack = 7;
    a.mana_special = 10;
    a.speed_special = 2;
    a.speed_simple = 1;
    a.defence = 2;
    a.speed = 1;
    a.renforce_simple_attack = 5;
    a.mana_renfrocement_simple_attack = 5;
    a.special_defence = 5;
    a.mana_defence = 10;
    
    b.name = "rodrygo";
    b.simple_attack = 3;
    b.special_attack = 7;
    b.mana_special = 10;
    b.speed_special = 2;
    b.speed_simple = 1;
    b.defence = 2;
    b.speed = 2;
    b.renforce_simple_attack = 4;
    b.mana_renfrocement_simple_attack = 5;
    b.special_defence = 6;
    b.mana_defence = 9;

    c.name = "garo";
    c.simple_attack = 3;
    c.special_attack = 7;
    c.mana_special = 10;
    c.speed_special = 2;
    c.speed_simple = 1;
    c.defence = 2;
    c.speed = 3;
    c.renforce_simple_attack = 6;
    c.mana_renfrocement_simple_attack = 6;
    c.special_defence = 6;
    c.mana_defence = 15;
    bool g = true;
    // while(g)
    // {
    //   main_menu(a,b,c,d11,d22,g);
    //   if(g)
    //   {
    //     game(d1,d2);
    //   }
    // }
}

void game(perso d1,perso d2)
{
  int round = 1,action1_no = 0,action2_no = 0;
  int p1_score = 0,p2_score = 0;
        // simple attack a 
        // attack number 1
        // special attack d  
        // attack number 2
        // simple attack renforcement a,w
        // attack number 3
        // simpke defence s
        // attack number 4
        // special defence s,w



        // simple attack j
        // attack number 1
        // special attack l  
        // attack number 2
        // simple attack renforcement j,i
        // attack number 3
        // simpke defence k
        // attack number 4
        // special defence k,i

        system("CLS");
        round_system(round);
        for(int i = 1; i <= round; i++)
        {
          bool y = true;
          while(y)
          {
            system("CLS");
            diplay1(d1.live,d2.live,d1.mana,d2.mana,d1,d2);
            if(d1.speed > d2.speed)
            {
              for(int j = 1; j < 3; j++)
              {
                system("CLS");
                diplay1(d1.live,d2.live,d1.mana,d2.mana,d1,d2);
                std::cout << "Player" << j << " " << "plays"<< std::endl;
                if(j == 1)
                {
                  collect_action(j,action1_no);
                  if(action1_no == 2 || action1_no == 3 || action1_no == 5) valid_play(action1_no,d1,j);
                  if(action1_no == 2 || action1_no == 3 || action1_no == 5)
                  {
                    if(action1_no == 2) mana_consumption(d1.mana,d1.mana_special);
                    else if(action1_no == 3) mana_consumption(d1.mana,d1.mana_renfrocement_simple_attack);
                    else mana_consumption(d1.mana,d1.mana_defence);
                  }
                  std::cout << "                                                  ";
                  std::cout <<"Player" << j << " chosed:  ";
                  if(action1_no == 1) std::cout << "Simple attack" <<  std::endl;
                  else if(action1_no == 2) std::cout << "Special attack" <<  std::endl;
                  else if(action1_no == 3) std::cout << "Renforced simple attack" <<  std::endl;
                  else if(action1_no == 4) std::cout << "Defence" <<  std::endl;
                  else std::cout << "Special defence" <<  std::endl;
                  Sleep(500);
                }
                else 
                {
                  collect_action(j,action2_no);
                  if(action2_no == 2 || action2_no == 3 || action2_no == 5) valid_play(action2_no,d2,j);
                  if(action2_no == 2 || action2_no == 3 || action2_no == 5)
                  {
                    if(action2_no == 2) mana_consumption(d2.mana,d2.mana_special);
                    else if(action2_no == 3) mana_consumption(d2.mana,d2.mana_renfrocement_simple_attack);
                    else mana_consumption(d2.mana,d2.mana_defence);
                  }
                  std::cout << "                                                  ";
                  std::cout <<"Player" << j << " chosed:   ";
                  if(action2_no == 1) std::cout << "Simple attack" <<  std::endl;
                  else if(action2_no == 2) std::cout << "Special attack" <<  std::endl;
                  else if(action2_no == 3) std::cout << "Renforced simple attack" <<  std::endl;
                  else if(action2_no == 4) std::cout << "Defence" <<  std::endl;
                  else std::cout << "Special defence" <<  std::endl;
                  Sleep(500);
                }
              }
            }
            else
            {
              for(int j = 2; j > 0; j--)
              {
                system("CLS");
                diplay1(d1.live,d2.live,d1.mana,d2.mana,d1,d2);
                std::cout << "Player" << j << " " << "plays"<< std::endl;
                if(j == 1)
                {
                  collect_action(j,action1_no);
                  if(action1_no == 2 || action1_no == 3 || action1_no == 5) valid_play(action1_no,d1,j);
                  if(action1_no == 2 || action1_no == 3 || action1_no == 5)
                  {
                    if(action1_no == 2) mana_consumption(d1.mana,d1.mana_special);
                    else if(action1_no == 3) mana_consumption(d1.mana,d1.mana_renfrocement_simple_attack);
                    else mana_consumption(d1.mana,d1.mana_defence);
                  }
                  std::cout << "                                                  ";
                  std::cout <<"Player" << j << " chosed:  ";
                  if(action2_no == 1) std::cout << "Simple attack" <<  std::endl;
                  else if(action1_no == 2) std::cout << "Special attack" <<  std::endl;
                  else if(action1_no == 3) std::cout << "Renforced simple attack" <<  std::endl;
                  else if(action1_no == 4) std::cout << "Defence" <<  std::endl;
                  else std::cout << "Special defence" <<  std::endl;
                  Sleep(500);
                }
                else 
                {
                  collect_action(j,action2_no);
                  if(action2_no == 2 || action2_no == 3 || action2_no == 5) valid_play(action2_no,d2,j);
                  if(action2_no == 2 || action2_no == 3 || action2_no == 5)
                  {
                    if(action2_no == 2) mana_consumption(d2.mana,d2.mana_special);
                    else if(action2_no == 3) mana_consumption(d2.mana,d2.mana_renfrocement_simple_attack);
                    else mana_consumption(d2.mana,d2.mana_defence);
                  }
                  std::cout << "                                                  ";
                  std::cout <<"Player" << j << " chosed:  ";
                  if(action2_no == 1) std::cout << "Simple attack" <<  std::endl;
                  else if(action2_no == 2) std::cout << "Special attack" <<  std::endl;
                  else if(action2_no == 3) std::cout << "Renforced simple attack" <<  std::endl;
                  else if(action2_no == 4) std::cout << "Defence" <<  std::endl;
                  else std::cout << "Special defence" <<  std::endl;
                  Sleep(500);
                }
              }
            }
            if(action1_no == 5)
            {
              if(action2_no != 4 && action2_no != 5)
              {
                if( action2_no == 1) d1.special_defence = d2.simple_attack;
                else if (action2_no == 2) d1.special_defence = d2.special_attack;
                else d1.special_attack = d2.mana_renfrocement_simple_attack;
              }
            }
            else if (action2_no == 5)
            {
              if(action1_no != 4 && action1_no != 5)
              {
                if( action1_no == 1) d2.special_defence = d1.simple_attack;
                else if (action1_no == 2) d2.special_defence = d1.special_attack;
                else d2.special_attack = d1.mana_renfrocement_simple_attack;
              }
            }
            if((action1_no == 1 || action1_no == 2 || action1_no == 3) && (action2_no == 4 || action2_no == 5))
            {
              if(action1_no == 1)
              {
                if(action2_no == 4) health_damage(attack_remain(d1.simple_attack,d2.defence),d2.live);
                else health_damage(attack_remain(d1.simple_attack,d2.special_defence),d2.live);
              }
              else if (action1_no == 2)
              {
                if(action2_no == 4) health_damage(attack_remain(d1.special_attack,d2.defence),d2.live); 
                else health_damage(attack_remain(d1.special_attack,d2.special_defence),d2.live);
              }
              else
              {
                if(action2_no == 4) health_damage(attack_remain(d1.renforce_simple_attack,d2.defence),d2.live);
                else health_damage(attack_remain(d1.renforce_simple_attack,d2.special_defence),d2.live);
              }
            }
            else if((action2_no == 1 || action2_no == 2 || action2_no == 3) && (action1_no == 4 || action1_no == 5))
            {
              if(action2_no == 1)
              {
                if(action1_no == 4) health_damage(attack_remain(d2.simple_attack,d1.defence),d1.live);
                else health_damage(attack_remain(d2.simple_attack,d1.special_defence),d1.live);
              }
              else if (action2_no == 2)
              {
                if(action1_no == 4) health_damage(attack_remain(d2.special_attack,d1.defence),d1.live);
                else health_damage(attack_remain(d2.special_attack,d1.special_defence),d1.live);
              }
              else
              {
                if(action1_no == 4) health_damage(attack_remain(d2.renforce_simple_attack,d1.defence),d1.live);
                else health_damage(attack_remain(d2.renforce_simple_attack,d1.special_defence),d1.live);
              }
            }
            else
            {
              if(action1_no == 1)
              {
                if(action2_no == 1)
                {
                  if(d1.simple_attack < d2.simple_attack) health_damage(attack_remain(d2.simple_attack,d1.simple_attack),d1.live);
                  else if(d1.simple_attack > d2.simple_attack) health_damage(attack_remain(d1.simple_attack,d2.simple_attack),d2.live); 
                  else{}
                }
                else if(action2_no == 2)
                {
                  if(d1.simple_attack < d2.special_attack) health_damage(attack_remain(d2.special_attack,d1.simple_attack),d1.live);
                  else if(d1.simple_attack > d2.special_attack) health_damage(attack_remain(d1.simple_attack,d2.special_attack),d2.live);
                  else{}
                }
                else if (action2_no == 3)
                {
                  if(d1.simple_attack < d2.renforce_simple_attack) health_damage(attack_remain(d2.renforce_simple_attack,d1.special_attack),d1.live);
                  else if(d1.simple_attack > d2.renforce_simple_attack) health_damage(attack_remain(d1.special_attack,d2.renforce_simple_attack),d2.live);
                  else{}
                }
              }
              else if (action1_no == 2)
              {
                if(action2_no == 1)
                {
                  if(d1.special_attack < d2.simple_attack) health_damage(attack_remain(d2.simple_attack,d1.special_attack),d1.live);
                  else if(d1.special_attack > d2.simple_attack) health_damage(attack_remain(d1.special_attack,d1.simple_attack),d2.live);
                  else{}
                }
                else if(action2_no == 2)
                {
                  if(d1.special_attack < d2.special_attack) health_damage(attack_remain(d2.special_attack,d1.special_attack),d1.live);
                  else if(d1.special_attack > d2.special_attack) health_damage(attack_remain(d1.special_attack,d2.special_attack),d2.live);
                  else{}
                }
                else if (action2_no == 3)
                {
                  if(d1.special_attack < d2.renforce_simple_attack) health_damage(attack_remain(d2.renforce_simple_attack,d1.special_attack),d1.live);
                  else if(d1.special_attack > d2.renforce_simple_attack) health_damage(attack_remain(d1.special_attack,d2.renforce_simple_attack),d2.live);
                  else{}
              }
            }
            else if (action1_no == 3)
            {
              if(action2_no == 1)
                {
                  if(d1.renforce_simple_attack < d2.simple_attack) health_damage(attack_remain(d2.simple_attack,d1.renforce_simple_attack),d1.live);
                  else if(d1.renforce_simple_attack > d2.simple_attack) health_damage(attack_remain(d1.renforce_simple_attack,d2.simple_attack),d2.live);
                  else{}
                }
                else if(action2_no == 2)
                {
                  if(d1.renforce_simple_attack < d2.special_attack) health_damage(attack_remain(d2.special_attack,d1.renforce_simple_attack),d1.live);
                  else if(d1.renforce_simple_attack > d2.special_attack) health_damage(attack_remain(d1.renforce_simple_attack,d2.special_attack),d2.live);
                  else{}
                }
                else if (action2_no == 3)
                {
                  if(d1.renforce_simple_attack < d2.renforce_simple_attack) health_damage(attack_remain(d2.renforce_simple_attack,d1.renforce_simple_attack),d1.live);
                  else if(d1.renforce_simple_attack > d2.renforce_simple_attack) health_damage(attack_remain(d1.renforce_simple_attack,d2.renforce_simple_attack),d2.live);
                  else{}
                }
            }
            else{}
        }
        if(d1.speed > d2.speed)
        {
          if(d2.live <= 0) 
          {
            std::cout << "Player 1 wins" << std::endl;
            p1_score++;
          }
          else if(d1.live <= 0)
          {
            std::cout << "Player 2 wins" << std::endl;
            p2_score++;
          }
        }
        else if(d1.speed < d2.speed)
        {
          if(d1.live <= 0) 
          {
            std::cout << "Player 2 wins" << std::endl;
            p2_score++;
          }
          else if(d2.live <= 0)
          {
            std::cout << "Player 1 wins" << std::endl;
            p1_score++;
          }
        }
        y = end_of_game(d1.live,d2.live);
      }
    }
    if(p1_score > p2_score) std::cout << "Player one wins" << std::endl;
    else std::cout << "Player two wins" << std::endl;
    while(true)
    {
      if(GetAsyncKeyState(VK_RETURN))
      {
        break;
      }
    }
}
