#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

int SUBINTERVALS = 100;

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

double simpsonsEstimation(int baseValue, int width, std::map<int, int> dataMap)
{
    return (width * (dataMap.at(baseValue) + (4 * dataMap.at(baseValue + width) + dataMap.at(baseValue + (2 * width))))) / 3;
}

std::map<int, int> dataToMap(int length, std::vector<std::vector<std::string>> data)
{

    std::map<int, int> dataMap;


    for (int i = 0; i < length; i++)
    {
        dataMap.insert({i, std::stoi(data[i][1])});
    }
    

    return dataMap;
}

int main(int argc, char const *argv[])
{
    /* code */

    std::filebuf fb;

    fb.open("data.csv", std::ios::in);

    std::istream is(&fb);

    std::vector<std::vector<std::string>> data;

    data = readCSV(is);

    int dataLength = data.size(); // number of data points

    int intervalWidth = dataLength / SUBINTERVALS;

    std::map<int, int> dataMap = dataToMap(dataLength, data);

    // for(std::pair<int, int> x : dataMap) {
    //     std::cout << x.first << " | " << x.second << std::endl;
    // }



}