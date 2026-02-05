#include <iostream>
#include <limits>
#include <cctype>

#include "cli.hpp"

namespace cli
{
    char read_choice(const std::string &prompt, const std::string &allowed)
    {
        while (true)
        {
            std::cout << prompt;
            std::string s;
            std::getline(std::cin, s);

            if (s.size() == 1)
            {
                char c = static_cast<char>(std::tolower(s[0]));
                if (allowed.find(c) != std::string::npos)
                    return c;
            }
            std::cout
                << "Invalid choice. Allowed: " << allowed << std::endl;
        }
    }

    int read_int(const std::string &prompt, int min_value, int max_value)
    {
        int x;

        while (true)
        {
            std::cout << prompt;
            
            if (std::cin >> x && x >= min_value && x <= max_value)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return x;
            }
            std::cout << "Invalid input! Enter a number in range! [" << min_value << "," << max_value << "].\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    double read_double(const std::string &prompt)
    {
        double x;

        while (true)
        {
            std::cout << prompt;
            if (std::cin >> x)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return x;
            }
            std::cout << "Invalid input! Enter a valid number!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}