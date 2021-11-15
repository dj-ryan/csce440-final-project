#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>


#include <chrono>
#include <random>

struct Extrema
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

    std::filebuf fb;

    fb.open("data.csv", std::ios::in);

    std::istream is(&fb);

    std::vector<std::vector<std::string>> data;

    data = readCSV(is);

    struct Extrema extrema = {0, 0};

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


    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<> dist(extrema.min, extrema.max);

    int length = data.size();
    int guess = 0, dataPoint = 0;
    double hit = 0; // total hits
    int accuracy = 100; // the number of guesses for each data point
    double totalGuesses = accuracy * length; // the number of guesses we will make
    double area = extrema.max * length; // the total area of the data 

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

    std::cout << "max: " << extrema.max << std::endl;
    std::cout << "min: " << extrema.min << std::endl;
    std::cout << "area: " << area << std::endl;

    std::cout << "length: " << length << " | accuracy: " << accuracy << " | Total guesses: " << totalGuesses << std::endl;

    std::cout << "Ratio: " << ratio << " | Hits: " << hit <<

        std::endl;
    
    std::cout << "AREA: " << ratio * area << std::endl;

    return 0;
}
