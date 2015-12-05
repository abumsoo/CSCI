#include "AppleFarmer.h"
#include <iostream>

using namespace std;


AppleFarmer::AppleFarmer(int initVal) {
  for (int i=0; i < 30; i++) {
    sales[i] = initVal;
    harvest[i] = initVal;
  }
}

AppleFarmer::~AppleFarmer()
{
    //dtor
}

void AppleFarmer::sellApples(int demand) {
  if (demand <= inventory) {
    sales[currentDay] = demand;
    inventory -= demand;
  } else {
    sales[currentDay] = 0;
  }
}

void AppleFarmer::harvestApples(int dayHarvest) {
  harvest[currentDay] = dayHarvest;
  inventory += dayHarvest;
}

bool AppleFarmer::endOfMonth() {
  if (currentDay == maxDays)
    return true;
  return false;
}

void AppleFarmer::updateCurrentDay() {
  currentDay += 1;
}

double AppleFarmer::calculateAverageHarvest() {
  int total = 0;
  for (int i=0; i < 30; i++) {
    total += harvest[i];
  }
  return total/30.0;
}

double AppleFarmer::calculateAverageSales() {
  int total = 0;
  for (int i=0; i < 30; i++) {
    total += sales[i];
  }
  return total/30.0;
}

int AppleFarmer::getInventory() {
  return inventory;
}

void AppleFarmer::printHarvest() {
  for (int i=0; i < 30; i++) {
    cout<<"Day: "<<i<<" Harvest: "<<harvest[i]<<endl;
  }
}

void AppleFarmer::printSales() {
  for (int i=0; i < 30; i++) {
    cout<<"Day: "<<i<<" Sales: "<<sales[i]<<endl;
  }
}
