#include <iostream>

// Function declarations

// int main()
//
// This program has the first player enter a secret number
// and then the other play must guess that number.
//
// Exercises:
//    1. Update this code so that Player A must enter a
//       number between 1 and 100, inclusive, and the
//       player is repeatedly asked to do this until that
//       player enters a valid number in this range.
//
//    2. Right now, Player B is only told if the guess was
//       right or wrong. Update this code so that it
//       displays one of three possible messages:
//          You guessed the secret number
//          Your guess is too high
//          Your guess is too low
//
//    3. This is fun: Suppose the user entered the integer
//       17 and you responded with 'Your guess is too high',
//       if the user enters a value >= 17, respond with
//          No, I already told you 17 was too high...
int main()
{
    int secret_number{};
    std::cout << "Player A: enter a secret number: ";
    std::cin >> secret_number;

    while ((secret_number < 1) || (secret_number > 100))
    {
        std::cout << "Integer out of range" << std::endl;
        std::cout << "Player A: enter a secret number: ";
        std::cin >> secret_number;
    }

    int prev_number{-2};
    while (true)
    {
        int guessed_number{};

        std::cout << "Player B: enter a guess: ";
        std::cin >> guessed_number;

        if (prev_number != -1)

        {

            if (guessed_number == secret_number)
            {
                std::cout << "You guessed the secret number"
                          << std::endl;
                break;
            }
            else if (guessed_number < secret_number)
            {
                if ((prev_number < secret_number) && (guessed_number < secret_number))
                {
                    std::cout << "Your guess is still too high" << std::endl;
                }
                else
                {
                    std::cout << "Your guess is too low"
                              << std::endl;
                }
            }
            else if (guessed_number > secret_number)
            {
                if ((prev_number > secret_number) && (guessed_number > secret_number))
                {
                    std::cout << "Your guess is still too high" << std::endl;
                }
                else
                {
                    std::cout << "Your guess is too high"
                              << std::endl;
                }
            }
        }
        prev_number = guessed_number;
    }

    return 0;
}