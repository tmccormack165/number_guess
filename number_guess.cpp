#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
//using std::cout, std::cin, std::string, std::endl;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int get_int(string prompt, bool is_guess, int answer){
    string user_input;
    int ui_int;

    cout << prompt;
    cin >> user_input;

    if(is_number(user_input) == true){
        ui_int = stoi(user_input);
    }
    else if(user_input == "q"){
        cout << "QUIT" << endl;
        if(is_guess == true){
            cout << "ANSWER: " << answer;
        }
        exit(1);
    }
    else{
        while(is_number(user_input) == false){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "=== Error Invalid Input ===" << endl;
            cout << prompt;
            cin >> user_input;
            if(user_input == "q"){
                cout << "QUIT" << endl;
                if(is_guess == true){
                    cout << "ANSWER: " << answer << endl;
                }
                exit(1);
            }
        }
    }
    
    return ui_int;
}

int main() {
    // declare variables
    int default_answer = 0;
    int min_number, max_number, number_range, answer, random_number, offset, guess;
    bool found_answer = false;
    bool is_guess = false;
    string min_prompt = "Enter the minimum number (Enter q to quit): ", max_prompt = "Enter the maximum number (Enter q to quit): ", guess_prompt = "Enter a Guess (Enter q to quit): ";
    

    // seed the random generator so that different numbers will be generated upon each execution
    srand(time(NULL));

    min_number = get_int(min_prompt, is_guess, default_answer);
    max_number = get_int(max_prompt, is_guess, default_answer);


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
    is_guess = true;

    while(found_answer == false){
        guess = get_int(guess_prompt, is_guess, answer);
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