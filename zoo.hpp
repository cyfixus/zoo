/**************************************
 * Author: Sean Foster
 * Date: 10/13/2017
 * Description: Zoo class header
**************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <cmath>
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "validator.hpp"


class Zoo
{

  private: 
    int day;
    double bank;
    int tigerCapacity;
    int turtleCapacity;
    int penguinCapacity;
    int tigerCount;
    int turtleCount;
    int penguinCount;
    bool bonus;
    bool keepPlaying;
    Tiger *tigers;
    Turtle *turtles;
    Penguin *penguins;

  public:
    Zoo();
    void zooIntro();
    void zooStatus();
    void bankStatement();
    void purchaseDay();
    void newDay();
    void game();
    void randomEvent();
    void attendenceBoom();
    void peacefulDay();
    void wantQuit();
    
    //animalManagement.cpp
    void addBabies(int, int);
    bool findParent(Animal*, int, int);
    bool newBaby();
    void purchaseAnimals(int);
    void purchaseAnimal(int, int);
    void ageAnimalsOneDay(Animal*, int);
    void ageAnimals();
    void feedAnimals();
    void addAnimal(Animal, Animal*, int);
    bool addTiger(int, bool);
    bool addPenguin(int, bool);
    bool addTurtle(int, bool);
    bool killAnimal();
    bool killSpecies();
    void removeAnimal(Animal*, int);
    bool removeTiger();
    bool removePenguin();
    bool removeTurtle();
    void clearZoo();
    void updateCounts();
    void updateTigerCount();
    void updatePenguinCount();
    void updateTurtleCount();
    void emptyCage(Animal*, int);
    void doubleTigerCage();
    void doublePenguinCage();
    void doubleTurtleCage();
    void killZoo();

    //moneyManagement.cpp
    void calcProfits();
    void adjustBalance(double);
    double totalPayoff();
    double tigerPayoff();
    double penguinPayoff();
    double turtlePayoff();
    double totalFoodCost();
    double tigerFoodCost();
    double penguinFoodCost();
    double turtleFoodCost();
    double tigerBonus();

};

#endif