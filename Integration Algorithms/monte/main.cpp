#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>


int ACCURACY = 1000;  // the number of guesses for each data point

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

    int length = data.size(); // number of data points
    int guess = 0, dataPoint = 0; // init empty vars
    double totalHits = 0; // total totalHits 
    double totalGuesses = ACCURACY * length; // the number of guesses we will make
    double area = extrema.max * length; // the total area of the data 

    for (int i = 0; i < length; i++)
    {
        // Looks up data point and converts it to int
        dataPoint = std::stoi(data.at(i).at(1));

        for (int i = 0; i < ACCURACY; i++)
        {
            // Generates a random guess in-between the limtis
            guess = dist(generate); 

            // Checks if the guess is lower then the actually value
            if (guess < dataPoint) 
            {
                // Keeps track of all hits
                totalHits++; 
            }
        }
    }

    double ratio = totalHits / totalGuesses;

    std::cout << "======== REPORT =========" << std::endl;

    std::cout << "max: " << extrema.max << std::endl;
    std::cout << "min: " << extrema.min << std::endl;
    std::cout << "area: " << area << std::endl;

    std::cout << "length: " << length << " | accuracy: " << ACCURACY << " | Total guesses: " << totalGuesses << std::endl;

    std::cout << "Ratio: " << ratio << " | Hits: " << totalHits <<

        std::endl;
    
    std::cout << "AREA: " << ratio * area << std::endl;

    return 0;
}
