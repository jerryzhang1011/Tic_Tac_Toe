#include <iostream>
#include <string>

using namespace std;

const char PLAYER1 = 'X';
const char PLAYER2 = 'O';


void input_player_name(string &p1, string &p2) {

    // read first player
    while (1) {
        cout << "Enter the name of the first player : " << endl;
        cin >> p1;
        if (cin.fail() || cin.eof()) {
            cin.clear();
            cin.ignore();
            cout << "\nHey, please enter a correct name!" << endl;
            continue;
        }
        break;
    }

    // read first player
    while (1) {
        cout << "Enter the name of the second player : " << endl;
        cin >> p2;
        if (cin.fail() || cin.eof()) {
            cin.clear();
            cin.ignore();
            cout << "\nHey, please enter a correct name!" << endl;
            continue;
        }
        break;
    }
}

void print_chart(const char *square) {
    cout << endl;
    cout << "-------------" << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << square[0] << " | " << square[1] << " | " << square[2] << " |" << endl;
    cout << "|   |   |   |" << endl;
    cout << "-------------" << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << square[3] << " | " << square[4] << " | " << square[5] << " |" << endl;
    cout << "|   |   |   |" << endl;
    cout << "-------------" << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << square[6] << " | " << square[7] << " | " << square[8] << " |" << endl;
    cout << "|   |   |   |" << endl;
    cout << "-------------" << endl << endl;
}

int ask_position (const string player, const char *square) {
    int position;
    while (1) {
        cout << player << ", please enter a position: " << endl;
        cin >> position;
        if (cin.fail() || cin.eof()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid position" << endl;
            continue;
        }
        if (position > 9 || position < 1) {
            cout << player << ", please enter a position from 1 to 9!" << endl;
            continue;
        }
        if (square[position - 1] == PLAYER1 || square[position - 1] == PLAYER2) {
            cout << "This position has been used!!" << endl;
            continue;
        }
        break;
    }
    return position;
}

bool check_win(const char *square) {
    bool win = false;
    // check columns
    for (int i = 0; i < 3; ++i) {
        if (square[i] == square[i + 3] && square[i] == square[i + 6]) {
            win = true;
            return win;
        }
    }

    // check rows
    for (int i = 0; i <= 6; i += 3) {
        if (square[i] == square[i + 1] && square[i] == square[i + 2]) {
            win = true;
            return win;
        }
    }

    // check slash
    if (square[0] == square[4] && square[0] == square[8]) {
        win = true;
        return win;
    }
    if (square[2] == square[4] && square[2] == square[6]) {
        win = true;
        return win;
    }

    return win;
}

void io_driver(string p1, string p2) {
    char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    print_chart(square);
    int round = 0;
    cout << p1 << " is player1, and will go first." << endl;
    cout << p2 << " is player2, and will go after " << p1 << "." << endl;
    while (round < 9) {
        int position;
        if (round % 2 == 0) { // player1 turn
            position = ask_position (p1, square);
            square[position - 1] = PLAYER1;
        } else { // player2 turn
            position = ask_position (p2, square);
            square[position - 1] = PLAYER2;
        }
        print_chart(square);

        bool win = check_win(square);
        if (win) {
            if (round % 2 == 0) {  //player1 win
                cout << p1 << " wins!\nGreat job!!" << endl; 
            } else {               // player2 win
                cout << p2 << " wins!\nGreat job!!" << endl; 
            }
            return;
        }
        ++round;
    }
    cout << "Oops, That is a tie!!!" << endl;
    return;
}

int main() {
    string p1;
    string p2;
    input_player_name(p1, p2);
    io_driver(p1, p2);
    while (1) {
        string input;
        cout << "Do you want to try again? (Y/N): " << endl;
        cin >> input;
        if (input == "Y" || input == "y") {
            io_driver(p1, p2);
        } else if (input == "N" || input == "n") {
            break;
        } else {
            cout << "That a terrible answer!!\nTry again" << endl;
        }
    }
    return 0;
}
