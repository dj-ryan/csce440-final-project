#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>

#include <chrono>
#include <random>

struct max_min
{
    int max;
    int min;
};

std::vector<std::string> readCSVRow(const std::string &row)
{
    std::vector<std::string> fields{""};
    size_t i = 0; // index of the current field
    for (char c : row)
    {
        switch (c)
        {
        case ',': // end of field
            fields.push_back("");
            i++;
            break;
        default:
            fields[i].push_back(c);
            break;
        }
    }
    return fields;
}

/// Read CSV file, Excel dialect. Accept "quoted fields ""with quotes"""
std::vector<std::vector<std::string>> readCSV(std::istream &in)
{
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof())
    {
        std::getline(in, row);
        if (in.bad() || in.fail())
        {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}

int main(int argc, char const *argv[])
{
    /* code */

    //std::ifstream f("data.csv");

    std::filebuf fb;

    fb.open("data.csv", std::ios::in);

    std::istream is(&fb);

    std::vector<std::vector<std::string>> data;

    data = readCSV(is);

    // print test output
    // std::cout << data.size() << std::endl;
    // std::cout << data.at(0).size()
    //           << std::endl;
    // std::cout << data.at(2).at(1) << std::endl;

    // std::pair<int, int> maxMin = {0, 0};

    struct max_min extrema = {0, 0};

    // find max and min values
    for (int i = 0; i < data.size(); i++)
    {
        int dataPoint = std::stoi(data.at(i).at(1));
        if (dataPoint > extrema.max)
        {
            extrema.max = dataPoint;
        }
        else if (dataPoint < extrema.min)
        {
            extrema.min = dataPoint;
        };
    }

    // print max and min
    std::cout << "max: " << extrema.max << std::endl;
    std::cout << "min: " << extrema.min << std::endl;

    // TODO: loop through values and randomly ping up

    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<> dist(extrema.min, extrema.max);

    int length = data.size();
    int guess = 0, dataPoint = 0;
    double hit = 0;
    int accuracy = 100;
    double totalGuesses = accuracy * length;

    for (int i = 0; i < length; i++)
    {

        dataPoint = std::stoi(data.at(i).at(1));

        for (int i = 0; i < accuracy; i++)
        {

            guess = dist(generate);

            if (guess < dataPoint)
            {
                hit++;
            }
        }
        std::cout << "index: " << i << " | point: " << dataPoint << " | hits: " << hit << std::endl;
    }

    double ratio = hit / totalGuesses;

    std::cout << "======== REPORT =========" << std::endl;

    std::cout << "length: " << length << " | accuracy: " << accuracy << " | Total guesses: " << totalGuesses << std::endl;

    std::cout << "Ratio: " << ratio << " | Hits: " << hit <<

        std::endl;
    
    std::cout << "AREA: " << ratio * (extrema.max * length) << std::endl;

    return 0;
}
