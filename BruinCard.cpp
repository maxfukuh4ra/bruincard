#include <string>
#include "BruinCard.h"

BruinCard::BruinCard()
{
    mBoughtAMealPlan = false;
}

void BruinCard::purchaseMealPlan(MealPlan plan)
{
    mPlan = plan;
    switch (mPlan.getPlan())
    {
        case REGULAR19:
        case PREMIER19:
        case REGULAR14:
        case PREMIER14:
        case REGULAR11:
        case PREMIER11:
            mBoughtAMealPlan = true;
            break;
        default:
            mBoughtAMealPlan = false;
            break;
    }
}

bool BruinCard::hasPurchasedMealPlan()
{
    return mBoughtAMealPlan;
}

plan BruinCard::getPlan()
{
    return mPlan.getPlan();
}

bool BruinCard::eat(meal m)
{
    
    if (mBoughtAMealPlan == false) // meal plan does not exist
        return false;
    else // meal plan exists
    {
        if (howManyMealsLeft <= 0)
            return false;
        switch (mPlan.getPlan())
        {
            case PREMIER11:
            case PREMIER14:
            case PREMIER19:
                switch (m)
                {
                    case BREAKFAST:
                        hasEatenBreakfast = true;
                        howManyMealsLeft--;
                        break;
                    case LUNCH:
                        hasEatenBreakfast = true;
                        howManyMealsLeft--;
                        break;
                    case DINNER:
                        hasEatenDinner = true;
                        howManyMealsLeft--;
                        break;
                    case WEEKENDBRUNCH:
                        hasEatenBrunch = true;
                        howManyMealsLeft--;
                        break;
                }
            break;
            case REGULAR11:
            case REGULAR14:
            case REGULAR19:
            {
                switch (m)
                {
                    case BREAKFAST:
                        if (hasEatenBreakfast == true)
                            return false;
                        else
                        {
                            hasEatenBreakfast = true;
                            howManyMealsLeft--;
                        }
                    break;
                    case LUNCH:
                        if (hasEatenLunch == true)
                            return false;
                        else
                        {
                            hasEatenLunch = true;
                            howManyMealsLeft--;
                        }
                    break;
                    case DINNER:
                        if (hasEatenDinner == true)
                            return false;
                        else
                        {
                            hasEatenDinner = true;
                            howManyMealsLeft--;
                        }
                    break;
                    case WEEKENDBRUNCH:
                        if (hasEatenBrunch == true)
                            return false;
                        else
                        {
                            hasEatenBrunch = true;
                            howManyMealsLeft--;
                        }
                    break;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}
 
void BruinCard::startQuarter()
{
  switch (mPlan.getPlan())
  {
      case PREMIER11:
          howManyMealsLeft = 121;
          break;
      case PREMIER14:
          howManyMealsLeft = 154;
          break;
      case PREMIER19:
          howManyMealsLeft = 209;
          break;
      case REGULAR11:
          howManyMealsLeft = 11;
          break;
      case REGULAR14:
          howManyMealsLeft = 14;
          break;
      case REGULAR19:
          howManyMealsLeft = 19;
          break;
  }
}

void BruinCard::newWeek()
{
    switch (mPlan.getPlan())
  {
      case REGULAR11:
          howManyMealsLeft = 11;
          break;
      case REGULAR14:
          howManyMealsLeft = 14;
          break;
      case REGULAR19:
          howManyMealsLeft = 19;
          break;
      default:
          break;
  }
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}

void BruinCard::newDay()
{
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}

int BruinCard::mealsLeftThisWeek()
{
    if (hasPurchasedMealPlan() == false)
        howManyMealsLeft = 0;
    return howManyMealsLeft;
}

int BruinCard::getBalance()
{
    balance = 0;

    return balance;
}
