#include <iostream>
#include <limits>
#include <cctype>

#include "cli.hpp"

// CLI utility functions for user input with validation
namespace cli
{
    /*
    * Read a single character choice from the user with validation. It will keep prompting until a valid choice is entered.
    * @param prompt The message to display to the user when asking for input.
    * @param allowed A string containing all valid characters that the user can enter (e.g., "ab" for choices 'a' and 'b').
    * @return The character entered by the user that is found in the allowed string.
    * 
    * This function converts the user's input to lowercase and checks if it is a single character that exists in the allowed string. If the input is invalid, it will display an error message and prompt the user again.
    */
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
    /*
    * Read an integer value from the user with validation. It will keep prompting until a valid integer within the specified range is entered.
    * @param prompt The message to display to the user when asking for input.
    * @param min_value The minimum acceptable integer value (inclusive).
    * @param max_value The maximum acceptable integer value (inclusive).
    * @return The integer value entered by the user that falls within the specified range.
    * This function handles invalid input by clearing the error state and ignoring the rest of the line, ensuring that the user can try again without issues.
    */
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

    /*
    * Read a double value from the user with validation. It will keep prompting until a valid double is entered.
    * @param prompt The message to display to the user when asking for input.
    * @return The double value entered by the user.
    * This function handles invalid input by clearing the error state and ignoring the rest of the line, ensuring that the user can try again without issues.
    */
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