#ifndef APPLEFARMER_H
#define APPLEFARMER_H


class AppleFarmer
{
    public:
        AppleFarmer(int);
        ~AppleFarmer();
        void sellApples(int);
        void harvestApples(int);
        bool endOfMonth();
        void updateCurrentDay();
        int getInventory();
        double calculateAverageHarvest();
        double calculateAverageSales();
        void printSales();
        void printHarvest();
    protected:
    private:
        int sales[30];
        int harvest[30];
        int maxDays = 30;
        int currentDay = 0;
        int inventory = 0;
};

#endif // APPLEFARMER_H
