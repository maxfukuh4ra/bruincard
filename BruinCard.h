#ifndef BruinCard_h
#define BruinCard_h
#include "MealPlan.h"
using namespace std;

class BruinCard
{
public:
    BruinCard();
    void purchaseMealPlan(MealPlan plan);
    bool hasPurchasedMealPlan();
    plan getPlan();
    bool eat(meal m);
    void startQuarter();
    void newWeek();
    void newDay();
    int mealsLeftThisWeek();
    int getBalance();
private:
    MealPlan mPlan;
    bool mBoughtAMealPlan;
    bool hasEatenBreakfast;
    bool hasEatenLunch;
    bool hasEatenDinner;
    bool hasEatenBrunch;
    int howManyMealsLeft;
    int balance;
};

#endif /* BruinCard_hpp */
