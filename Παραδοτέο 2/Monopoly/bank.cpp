#include "bank.h"

// TODO: Implement here the methods of Bank

int Bank::getMoney(){
    return money;
}

int Bank::getFreeParkMoney(){
    return freeParkMoney;
}

void Bank::giveMoneyToBank(int amount){
    money += amount;
}

void Bank::takeMoneyFromBank(int amount){
    money -= amount;
}

void Bank::giveMoneyToFreePark(int amount){
    freeParkMoney += amount;
}

int Bank::takeFreeParkMoney(){  //??? better as void? how to return value before making it 0? could i use a temp?
    freeParkMoney = 0;
}

Bank::Bank(){   //initializing
    money = 20580;
    freeParkMoney = 0;
}
