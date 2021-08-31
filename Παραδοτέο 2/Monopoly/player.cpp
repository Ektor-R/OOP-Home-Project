#include <iostream>
#include <sstream>

#include "player.h"

using namespace std;

// TODO: Implement here the methods of Player

int Player::getId(){
    return id;
}

int Player::getLocation(){
    return location;
}

int Player::getMoney(){
    return money;
}

string Player::getName(){
    return name;
}

void Player::setLocation(int spaceNum){
    location = spaceNum;
}

void Player::giveMoneyToPlayer(int amount){
    money += amount;
}

void Player::takeMoneyFromPlayer(int amount){
    money -= amount;
}

Player::Player(int playerId){   //initialization
    money = 1500;
    location = 0;
    id = playerId;  //???
    if (id==0)
        name = "Player 1";

    else
        name = "Player 2";
}
