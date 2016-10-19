#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int countBorders(const std::vector<double> &histogram)
{
    int size = static_cast<int>(histogram.size());
    int numOfBorders{0};
    for (int i = 0; i<size; ++i)
    {
        double l, r, o = histogram[i];
        if (i==0) l = 0.0;
        else l = histogram[i-1];
        if (i==size-1) r = 0.0;
        else r = histogram[i+1];

        if ((i==0 && r >= 0.05) || (i==size-1 && l >=0.05)) o = 0.0;
        if (l >= 0.05 && o < 0.05 && r < 0.05) ++numOfBorders;
        if (l < 0.05 && o < 0.05 && r >= 0.05) ++numOfBorders;
    }

    return numOfBorders;
}

int main()
{
   std::vector<double> histXGen;
   // std::vector<double> histPGen;
   // std::vector<double> histQGen;
    histXGen.push_back(0.5);
    histXGen.push_back(0.7);
    histXGen.push_back(0.5);


    int numOfLineages = countBorders(histXGen) / 2;

    std::cout << numOfLineages;




    return 0;
}
