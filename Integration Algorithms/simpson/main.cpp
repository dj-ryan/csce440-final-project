#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>


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

}