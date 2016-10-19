#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int countBorders(const std::vector<double> &histogram);
std::string getNextLine(std::istream &file);
std::vector<std::vector<double>> getHistograms(const std::string line, const int histw);

int main()
{
    std::vector<double> histXGen;
    std::vector<double> histPGen;
    std::vector<double> histQGen;
    std::ifstream file("histograms.csv");

    std::cout << getNextLine(file) << "\n\n";


    // std::vector<int> numOfLineages;
    // numOfLineages.push_back(countBorders(histXGen) / 2);
    // numOfLineages.push_back(countBorders(histPGen) / 2);

    // int maxLineages = *std::max_element(numOfLineages.begin(), numOfLineages.end());

    return 0;
}

std::string getNextLine(std::istream &file)
{
    std::string line;
    std::getline(file, line);
    return line;
}



int countBorders(const std::vector<double> &histogram)
{
    bool empty = histogram.empty();

    if (empty) throw std::invalid_argument("Histogram is empty");
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
