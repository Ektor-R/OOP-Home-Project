#include <iostream>

#include "actions.h"

using namespace std;

int makeMove(Bank &bank, Player players[], int playerTurn, int diceRoll)
{
    // TODO: Implement this function

    if ((players[playerTurn].getLocation() + diceRoll) <= 39)
       players[playerTurn].setLocation(players[playerTurn].getLocation() + diceRoll);
    else {
        players[playerTurn].setLocation((players[playerTurn].getLocation() + diceRoll) - 40);   //moving through starting point
        bank.takeMoneyFromBank(200);
        players[playerTurn].giveMoneyToPlayer(200);
    }

    return players[playerTurn].getLocation();
}

void makeAction(Bank &bank, Player players[], Space spaces[], int playerTurn, int newSpace)
{
    // TODO: Implement this function

    if ((spaces[newSpace].getType() == "Property") || (spaces[newSpace].getType() == "RailRoad") || (spaces[newSpace].getType() == "Utility")){
       if (spaces[newSpace].getOwner() == 1-playerTurn){    //other player owns the block
        players[playerTurn].takeMoneyFromPlayer(spaces[newSpace].getRent());
        players[1-playerTurn].giveMoneyToPlayer(spaces[newSpace].getRent());
       }
       else if (spaces[newSpace].getOwner() == -1){ //the bank owns the block
        if (players[playerTurn].getMoney() >= 5*spaces[newSpace].getBuyingCost()){  //checking if player has enough money
            players[playerTurn].takeMoneyFromPlayer(spaces[newSpace].getBuyingCost());
            bank.giveMoneyToBank(spaces[newSpace].getBuyingCost());
            spaces[newSpace].setOwner(playerTurn);
        }
       }
    }
    else if (spaces[newSpace].getType() == "Tax"){
        players[playerTurn].takeMoneyFromPlayer(spaces[newSpace].getTax());
        bank.giveMoneyToFreePark(spaces[newSpace].getTax());
    }
    else if (spaces[newSpace].getType() == "FreeParking"){
        players[playerTurn].giveMoneyToPlayer(bank.getFreeParkMoney());
        bank.takeFreeParkMoney();
    }
    else if (spaces[newSpace].getType() == "GoJail"){
        players[playerTurn].setLocation(10);
        players[playerTurn].takeMoneyFromPlayer(200);
        bank.giveMoneyToFreePark(200);
    }
}
