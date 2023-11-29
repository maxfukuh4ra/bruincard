#include <string>
#include "MealPlan.h"

MealPlan::MealPlan() // constructor to initialize even if the driver code does not have any parameters
{
}

void MealPlan::pickPlan(plan p) // set the mPlan of MealPlan to p
{
    mPlan = p;
}

plan MealPlan::getPlan()
{
    return mPlan;
}

double MealPlan::cost()
{
    double cost;
    switch (mPlan)
    {
        case PREMIER19:
            cost = 5898.20;
            break;
        case REGULAR19:
            cost = 5278.20;
            break;
        case PREMIER14:
            cost = 5570.04;
            break;
        case REGULAR14:
            cost = 5107.20;
            break;
        case PREMIER11:
            cost = 5018.28;
            break;
        case REGULAR11:
            cost = 4646.64;
            break;
    }
    return cost;
}

bool MealPlan::unusedMealsCarryOver()
{
    bool doesCarryOver;
    switch (mPlan)
    {
        case PREMIER19:
        case PREMIER14:
        case PREMIER11:
            doesCarryOver = true;
            break;
        case REGULAR19:
        case REGULAR14:
        case REGULAR11:
            doesCarryOver = false;
            break;
    }
    return doesCarryOver;
}

int MealPlan::mealsEachWeek()
{
    int mealsEachWeek;
    switch (mPlan)
    {
        case PREMIER19:
        case REGULAR19:
            mealsEachWeek = 19;
            break;
        case PREMIER14:
        case REGULAR14:
            mealsEachWeek = 14;
            break;
        case PREMIER11:
        case REGULAR11:
            mealsEachWeek = 11;
            break;
    }
    return mealsEachWeek;
}

