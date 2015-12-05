#include <iostream>
#include "AppleFarmer.h"

using namespace std;

int main() {
  AppleFarmer farmerBob(0);
  int demand;
  int dayHarvest;
  while (farmerBob.endOfMonth() == false) {
    cout << "Enter a harvest amount: " << endl;
    cin >> dayHarvest;
    farmerBob.harvestApples(dayHarvest);
    cout << "Enter a sales amonut: " << endl;
    cin >> demand;
    farmerBob.sellApples(demand);
    cout << "Apple inventory: " << farmerBob.getInventory() << endl;
    farmerBob.updateCurrentDay();
  }
  cout << "Average harvest: " << farmerBob.calculateAverageHarvest() << endl;
  cout << "Average sales: " << farmerBob.calculateAverageSales() << endl;
  return 0;
}
