#include <iostream>
#include <random>
#include <string>
#include <cstring>

/* Simple program that returns a random number between the range given, respresented as
 * [argv[1], argv[2])
 * meaning that the range is from the first argument up to but not including the second argument.
 */
int main(int argc, char **argv)
{
    if (argc != 3) 
    {
        std::cout << "Usage: " << *argv << " (int)low (int)high\n" 
                     "       Where the range is [low, high)" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::mt19937 rng(std::random_device{}());

    try
    {
        
        int start = std::stoi(argv[1]);
        int end = std::stoi(argv[2]) - 1;

        if (start == end)
            throw std::invalid_argument("If the starting value is going to be equal to the ending value, you already have the value you want!");

        std::uniform_int_distribution<int> dist((int)start, (int)end);
        std::cout << dist(rng) << std::endl;
    }
    catch (std::invalid_argument& e)
    {
        if (strcmp(e.what(), "stoi") == 0)
            std::cout << "ALL OF MY ARGUMENTS SHOULD BE NUMBERS ASSHOLE!" << std::endl;
        else
            std::cout << e.what() << std::endl;

        exit(EXIT_FAILURE);
    };

    exit(EXIT_SUCCESS);
}
