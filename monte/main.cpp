#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>

#include <chrono>
#include <random>





enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> readCSVRow(const std::string &row) {
    CSVState state = CSVState::UnquotedField;
    std::vector<std::string> fields {""};
    size_t i = 0; // index of the current field
    for (char c : row) {
        switch (state) {
            case CSVState::UnquotedField:
                switch (c) {
                    case ',': // end of field
                              fields.push_back(""); i++;
                              break;
                    case '"': state = CSVState::QuotedField;
                              break;
                    default:  fields[i].push_back(c);
                              break; }
                break;
            case CSVState::QuotedField:
                switch (c) {
                    case '"': state = CSVState::QuotedQuote;
                              break;
                    default:  fields[i].push_back(c);
                              break; }
                break;
            case CSVState::QuotedQuote:
                switch (c) {
                    case ',': // , after closing quote
                              fields.push_back(""); i++;
                              state = CSVState::UnquotedField;
                              break;
                    case '"': // "" -> "
                              fields[i].push_back('"');
                              state = CSVState::QuotedField;
                              break;
                    default:  // end of quote
                              state = CSVState::UnquotedField;
                              break; }
                break;
        }
    }
    return fields;
}

/// Read CSV file, Excel dialect. Accept "quoted fields ""with quotes"""
std::vector<std::vector<std::string>> readCSV(std::istream &in) {
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof()) {
        std::getline(in, row);
        if (in.bad() || in.fail()) {
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

    std::istream















    



    // std::ifstream f("data.json");
    // json j;
    // f >> j;

    // j.

    // // std::ofstream o("pretty.json");
    // // o << std::setw(4) << j << std::endl;

    // // std::vector<std::uint8_t> v = {'t', 'r', 'u', 'e'};
    // // j = json::parse(v.begin(), v.end());

    // // for (json::iterator it = j.begin(); it != j.end(); ++it) {
    // //   std::cout << *it << '\n';
    // // }

    // j.begin();



    // for (json::iterator it = j.begin(); it != j.end(); ++it)
    // {
    //     std::cout << /** it.key() << */" : " << it.value() << "\n";

        
    // }



    // // std::cout << "File size: " << j.size() << std::endl;

    // std::vector<double> v;


    // std::random_device rand;
    // std::mt19937 generate(rand());
    // std::uniform_real_distribution<double> dist(0, 100);

    // int length = 10 * 100;
    // int guess = 0;
    // double hit = 0;
    // double miss = 0;

    // for (double i = 0; i < length; i = i + 0.1)
    // {
    //     v.push_back(i);
    // }

    // std::cout << v.at(1000) << std::endl;

    // // for (int i = 0; i < length; i++)
    // // {

    // //     guess = dist(generate);

    // //     if (guess < v.at(i))
    // //     {
    // //         hit++;
    // //     }
    // //     else
    // //     {
    // //         miss++;
    // //     }
    // // }

    // double ratio = hit / miss;

    // std::cout << "Ratio: " << ratio << " | Hits: " << hit << " | Misses: " << miss << 
    
    // std::endl;

    

    return 0;
}
