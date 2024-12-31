#include "header.h"
#include <iostream>
#include <windows.h>
#include <time.h>
// #include <string>

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


void round_system(int& round)
{
    round = 1;
    while(true)
    {
        system("CLS");
       if(GetAsyncKeyState(VK_LEFT)) 
       {
            if (round == 3) round = 1;
       }
       else if(GetAsyncKeyState(VK_RIGHT))
       {
            if (round == 1) round = 3;
       }
       else if(GetAsyncKeyState(VK_RETURN)) break;
       if(round == 1) std::cout << "Number of round  " << std ::endl << "       " << round << "  "<< "\033[31m>\033[37m" << std::endl;
       else std::cout << "Number of round  " << std::endl << "    "<< "\033[31m<\033[37m" << "  "<<round << std::endl;
       Sleep(100);
    }
}
void upper_case(std::string word)
{
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= ('a' - 'A');
        }
    }
    std::cout << "\033[31m" << word << "\033[37m" << std::endl;
}
void main_menu(perso a,perso b,perso c,perso * d1,perso * d2,bool& t)
{
    int m = 1;
    int n = 1;
    bool g = true;
     while(g)
    {
        system("CLS");
        if(n == 1)
        {
            std::cout << "\033[31m" << "1 VS 1" << "\033[37m" << std::endl << "vs AI" << std::endl<<"settings" << std::endl<< "exit"; 
        }
        else if (n == 2)
        {
            std::cout << "1 vs 1" << std::endl << "\033[31m" << "VS AI"<< "\033[37m" << std::endl <<"settings" << std::endl<< "exit";
        }
        else if(n == 4)
        {
            std::cout << "1 vs 1" << std::endl << "vs AI" << std::endl<<"settings" << std::endl << "\033[31m" << "EXIT" << "\033[37m";
        }
        else 
        {
            std::cout << "1 vs 1" << std::endl << "vs AI" << std::endl<< "\033[31m" <<"SETTINGS" << "\033[37m"<< std::endl << "exit" ;
        }
        if(GetAsyncKeyState(VK_UP))
        {
            if(n == 1) n = 4;
            else if ( n == 2) n = 1;
            else if(n == 3) n = 2;
            else n = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            if(n == 1) n = 2;
            else if (n == 2) n = 3;
            else if(n == 3)n = 4;
            else n = 1;
        }
        if(GetAsyncKeyState(0X0D))
        {
           g = false;
        }
        Sleep(100);
    }
    if(n == 1)
    {
        for(int i = 1; i <= 2; i++)
        {
            player_select(n,m,a,b,c,d1,d2,i,t);
        }
    }
    else if (n == 2) 
    {
        player_select(n,m,a,b,c,d1,d2,0,t);
        srand(time(0));
        int choice = 1 + rand() % 3;
        if(choice == 1) (*d2)= a;
        else if ( choice == 2 ) (*d2) = b;
        else (*d2) = c;
    }
    else if(n == 4)t = false;
    else
    {
        display_settings(a,b,c,d1,d2,t);
    }
}
void player_select(int& n,int& m,perso a,perso b,perso c,perso *d1,perso* d2,int i,bool& t)
{
    n = 1; m = 1;
    bool g = true;
     while(g)
    {
        system("CLS");
        if(n == 1)
        {
            if(i != 0)std::cout << "player" << i << " " << "chose your avatar" << std::endl<< std::endl;
            else std::cout << "Chose an avatar" << std::endl;
            upper_case(a.name);
            std::cout << b.name << std::endl;
            std::cout << c.name<< std::endl; 
            std::cout << "back";
        }
        else if(n == 2)
        {
            if(i != 0)std::cout << "player" << i << " " << "chose your avatar" << std::endl<< std::endl;
            else std::cout << "Chose an avatar" << std::endl;
            std::cout << a.name << std::endl;
            upper_case(b.name); 
            std::cout << c.name << std::endl;
            std::cout << "back";
        }
        else if (n == 3)
        {
            if(i != 0)std::cout << "player" << i << " " << "chose your avatar" << std::endl<< std::endl;
            else std::cout << "Chose an avatar" << std::endl;
            std::cout << a.name << std::endl;
            std::cout << b.name << std::endl;
            upper_case(c.name);
            std::cout << "back";
        }
        else
        {
            if(i != 0)std::cout << "player" << i << " " << "chose your avatar" << std::endl<< std::endl;
            else std::cout << "Chose an avatar" << std::endl;
            std::cout << a.name << std::endl;
            std::cout << b.name << std::endl;
            std::cout << c.name << std::endl;
            std::cout << "\033[31m" << "BACK" << "\033[37m";
        }
        if(GetAsyncKeyState(VK_UP))
        {
            if(n == 1) n = 4;
            else if ( n == 2) n = 1;
            else if (n == 3) n = 2;
            else n = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            if(n == 1) n = 2;
            else if (n == 2) n = 3;
            else if(n == 3) n = 4;
            else n = 1;
        }
        if(GetAsyncKeyState(0X0D))
        {
            g = false;
        }
        Sleep(100);
    }
    if(n != 4) player_aproval(n,m,a,b,c,d1,d2,i,t);
    else main_menu(a,b,c,d1,d2,t);
}
void player_aproval(int& n,int& m,perso a,perso b,perso c,perso * d1,perso * d2,int i,bool& t)
{
    m = 1;
    bool g = true;
    while(g)
    {
        system("CLS");
        if(m == 1)
        {
            std::cout << "\033[31m" << "VIEW STATS" << "\033[37m" << std::endl << "select" << std::endl << "back" << std::endl <<"main menu";
        }
        else if (m == 2)
        {
            std::cout << "view stats" << std::endl << "\033[31m" << "SELECT"<< "\033[37m" << std::endl << "back"<< std::endl << "main menu";
        }
        else if (m == 3)
        {
            std::cout << "view stats" << std::endl << "select" << std::endl << "\033[31m" << "BACK" << "\033[37m" << std::endl << "main menu";
        }
        else
        {
            std::cout << "view stats" << std::endl << "select" << std::endl << "back" << std::endl <<  "\033[31m" << "MAIN MENU" << "\033[37m" ;
        }
        if(GetAsyncKeyState(VK_UP))
        {
            if(m == 1) m = 4;
            else if ( m == 2) m = 1;
            else if( m == 3) m = 2;
            else m = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            if(m == 1) m = 2;
            else if (m == 2) m = 3;
            else if(m == 3)m = 4;
            else m = 1;
        }
        if(GetAsyncKeyState(0X0D))
        {
           g = false;
        }
        Sleep(100);
    }
    if(m == 3) player_select(n,m,a,b,c,d1,d2,i,t);
    else if(m == 2)
    {
        if(i == 1)
        {
            if(n == 1) (*d1) = a;
            else if (n==2) (*d1) = b;
            else (*d1) = c;
        }
        else 
        {
            if(n == 1) (*d2) = a;
            else if (n==2) (*d2) = b;
            else (*d2) = c;
        }
    }
    else if (m == 1)
    {
      perso z;
      if(n == 1) 
      {
        stats(a); 
        z = a;
      }
      else if (n == 2) 
      {
        stats(b); 
        z = b;
      }
      else 
      {
        stats(c); 
        z = c;
      }
      bool g = true;
      int h = 1;
      while(g)
      {
        system("CLS");
        stats(z); 
        if(h == 1) std::cout << "\033[31m" << "SELECT" << "\033[37m" << "       " << "back";
        else std::cout << "select" << "       "<< "\033[31m" << "BACK" << "\033[37m" << std::endl;
        if(GetAsyncKeyState(VK_LEFT))
        {
            if(h == 1) h = 2;
            else h = 1;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if(h == 1) h = 2;
            else h = 1;
        }
        if(GetAsyncKeyState(VK_RETURN))
        {
            g = false;
        }
        Sleep(100);
      }
      if(h == 2) player_aproval(n,m,a,b,c,d1,d2,i,t);
      else 
      {
        if(i == 1)
        {
            if(n == 1) (*d1) = a;
            else if (n==2) (*d1) = b;
            else (*d1) = c;
        }
        else 
        {
            if(n == 1) (*d2) = a;
            else if (n==2) (*d2) = b;
            else (*d2) = c;
        }
      }
    }
    else main_menu(a,b,c,d1,d2,t);
}
bool mana_sufficiency(int mana,int attack)
{
    return (mana > attack) ? true : false;
}
bool end_of_game(int live1,int live2)
{
    if(live1 <= 0 || live2 <= 0)
    {
        return false;
    }
    else return true;
}
void mana_consumption(int& mana,int attack)
{
    mana = mana - attack;
}
void health_damage(int attack,int& health)
{
    health = health - attack;
}
int attack_remain(int attack,int defence)
{
    if((attack - defence) < 1) return 0;
    else return attack - defence;
}
void collect_action(int player,int& action_no)
{
    if(player == 1)
    {
        // simple attack a 
        // attack number 1
        // special attack d  
        // attack number 2
        // simple attack renforcement a,w
        // attack number 3
        // simpke defence s
        // attack number 4
        // special defence s,w
        // attack number 5
        while(true)
        {
            if(GetAsyncKeyState(0x41))
            { 
                int i = 0;
                bool g = false;
                while(true)
                {
                    if(GetAsyncKeyState(0x57))
                    {
                        g = true;
                        action_no = 3;
                        break;
                    }
                    if(i == 5) break;
                    i++;
                    Sleep(100);
                }
                if(!g) action_no = 1;
                break;
            }
            else if (GetAsyncKeyState(0x44))
            {
                action_no = 2;
                break;
            }
            else if(GetAsyncKeyState(0x53))
            {
                int i = 0;
                bool g = false;
                while(true)
                {
                    if(GetAsyncKeyState(0x57))
                    {
                        g = true;
                        action_no = 5;
                        break;
                    }
                    if(i == 5) break;
                    i++;
                    Sleep(100);
                }
                if(!g) action_no = 4;
                break;
            }
        }
    }
    else 
    {
        // simple attack j
        // attack number 1
        // special attack l  
        // attack number 2
        // simple attack renforcement j,i
        // attack number 3
        // simpke defence k
        // attack number 4
        // special defence k,i




        while(true)
        {
            if(GetAsyncKeyState(0x4A))
            { 
                int i = 0;
                bool g = false;
                while(true)
                {
                    if(GetAsyncKeyState(0x49))
                    {
                        g = true;
                        action_no = 3;
                        break;
                    }
                    if(i == 5) break;
                    i++;
                    Sleep(100);
                }
                if(!g) action_no = 1;
                break;
            }
            else if (GetAsyncKeyState(0x4C))
            {
                action_no = 2;
                break;
            }
            else if(GetAsyncKeyState(0x4B))
            {
                int i = 0;
                bool g = false;
                while(true)
                {
                    if(GetAsyncKeyState(0x49))
                    {
                        g = true;
                        action_no = 5;
                        break;
                    }
                    if(i == 5) break;
                    i++;
                    Sleep(100);
                }
                if(!g) action_no = 4;
                break;
            }

        }

    }


}
void valid_play(int& action_no,perso a,int player)
{
    int d,i = 0;
    if(action_no == 2) d = a.special_attack;
    else if (action_no == 3) d = a.mana_renfrocement_simple_attack;
    else if (action_no == 5) d = a.mana_defence;
    
    while(!(mana_sufficiency(a.mana,d)))
    {
      if(i > 0)std::cout << "Insufficienct mana for this action" << std::endl << "Play" << std::endl;
      collect_action(player,action_no);
      if(action_no != 2 && action_no != 3 && action_no != 5) break;
      else if(action_no == 2) d = a.special_attack;
      else if (action_no == 3) d = a.mana_renfrocement_simple_attack;
      else d = a.mana_defence;
      i++;
      Sleep(100);
    }
}
void display_settings(perso a,perso b,perso c,perso * d1,perso * d2,bool& t)
{
    bool g = true;
    while(g)
    {
        system("CLS");
        std::cout << "  Player1 controls " << std::endl;
        std::cout << "simple attack : a" << std::endl; 
        std::cout << "Renforced simple attack : a & w" << std::endl;
        std::cout << "Special attack : d" << std::endl;
        std::cout << "Defence : s " << std::endl;
        std::cout << "special defence : s & w" << std::endl << std::endl;
        std::cout << "  Player2 controls " << std::endl;
        std::cout << "simple attack : j" << std::endl; 
        std::cout << "Renforced simple attack : j & i" << std::endl;
        std::cout << "Special attack : l" << std::endl;
        std::cout << "Defence : k " << std::endl;
        std::cout << "special defence : k & i" << std::endl<<std::endl;
        std::cout << "\033[31m" << "BACK" << "\033[37m";
        if(GetAsyncKeyState(VK_RETURN))
        {
            g = false;
        }
        Sleep(100);
    }
    main_menu(a,b,c,d1,d2,t);
}
