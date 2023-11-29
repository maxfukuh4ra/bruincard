#ifndef MealPlan_h
#define MealPlan_h
#include "Enums.h"
using namespace std;


class MealPlan // holds a single plan enumerated value data member
{
public:
    MealPlan(); // constructor
    void pickPlan(plan p);
    plan getPlan();
    double cost();
    int mealsEachWeek();
    bool unusedMealsCarryOver();
private:
    plan mPlan;
};

#endif /* MealPlan_hpp */
