#ifndef __header_h_
#define __header_h_
#include <iostream>


// Procedures and function for game.cpp
void diplay1(int live1,int live2,int mana1,int mana2,struct perso a,struct perso b);
void display_live_mana(int live_or_mana);
void stats(struct perso a);
void display_grid(int board[22][118]);
void attack_move(int board[22][118]);
void display_actions(int board[22][118]);




// Procedures and function for otherfunction.cpp
void stats(perso a);
void round_system(int& round);
void upper_case(std::string word);
void main_menu(struct perso a,struct perso b,struct perso c,struct perso * d1,struct perso * d2,bool& t);
void player_select(int& n,int& m,struct perso a,struct perso b,struct perso c,struct perso * d1,struct perso * d2, int i,bool& t);
void player_aproval(int& n,int& m,struct perso a,struct perso b,struct perso c,struct perso * d1,struct perso * d2,int i,bool& t);
bool mana_sufficiency(int mana,int attack);
bool end_of_game(int live1,int live2);
void mana_consumption(int& mana,int attack);
void health_damage(int attack,int& health);
int attack_remain(int attack,int defence);
void collect_action(int player,int& action_no);
void valid_play(int& action_no,perso a,int player);
void display_settings(perso a,perso b,perso c,perso * d1,perso * d2,bool& t);

#endif