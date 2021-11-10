#include <fstream>
#include <iostream>
#include <vector>

#include <chrono>
#include <random>

#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char const *argv[])
{
    /* code */

    // std::ifstream i("data.json");
    // json j;
    // i >> j;

    // std::ofstream o("pretty.json");
    // o << std::setw(4) << j << std::endl;

    // std::vector<std::uint8_t> v = {'t', 'r', 'u', 'e'};
    // j = json::parse(v.begin(), v.end());

    // for (json::iterator it = j.begin(); it != j.end(); ++it) {
    //   std::cout << *it << '\n';
    // }

    // for (json::iterator it = j.begin(); it != j.end(); ++it)
    // {
    //     std::cout << it.key() << " : " << it.value() << "\n";
    // }

    // std::cout << "File size: " << j.size() << std::endl;

    std::vector<double> v;


    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_real_distribution<double> dist(0, 100);

    int length = 10 * 100;

    int guess = 0;

    double hit = 0;
    double miss = 0;

    for (double i = 0; i < length; i = i + 0.1)
    {
        v.push_back(i);
    }

    std::cout << v.at(1000) << std::endl;

    for (int i = 0; i < length; i++)
    {

        guess = dist(generate);

        if (guess < v.at(i))
        {
            hit++;
        }
        else
        {
            miss++;
        }
    }

    double ratio = hit / miss;

    std::cout << "Ratio: " << ratio << " | Hits: " << hit << " | Misses: " << miss << std::endl;

    return 0;
}
