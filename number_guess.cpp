#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
//using std::cout, std::cin, std::string, std::endl;


int main() {
    // declare variables
    int min_number, max_number, number_range, answer, random_number, offset, guess;
    bool found_answer;

    // seed the random generator so that different numbers will be generated upon each execution
    srand(time(NULL));

    // Get the minimum and maximum of possible hidden values
    cout << "Enter the minimum number: ";
    cin >> min_number;

    cout << "Enter the maximum number: ";
    cin >> max_number;

    // Calculate the range
    number_range = max_number - min_number;

    // Increment the number range so that the upper bound of the range is a possible answer
    number_range++;

    // Generate a random number
    random_number = rand();

    // calculate the offset value using the modulo operator
    // the values of offset can range from 0 to 1 - number_range
    offset = random_number % number_range;
    answer = min_number + offset;

    while(found_answer == false){
        cout << "Enter a Guess (Enter <-1> to quit): ";
        cin >> guess;
        if(guess == -1){
            cout << "The real answer was: " << answer << endl;
            found_answer = true;
        }
        else if(guess == answer){
            cout << "That's Right!" << endl;
            found_answer = true; 
        }
        else if(guess < answer){
            cout << "The answer is higher than " << guess << endl;
        }
        else{
            cout << "The answer is lower than " << guess << endl;
        }
    }

    return 0;
}