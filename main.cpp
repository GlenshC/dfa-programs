#include <iostream>
#include <string>
using namespace std;

/*
q0 start
q4 final

q0 a q1
q1 a q1
q2 a q3
q3 a q1
q4 a q4

q0 b q0
q1 b q2
q2 b q0
q3 b q4
q4 b q4
*/

/*  PROBLEM 1 */
bool problem1(const string& s) {
    enum State { Q0, Q1, Q2, Q3, Q4 };
    State state = Q0; // starting

    for (char c : s) {
        if (c != 'a' && c != 'b') return false;
        switch (state) {
            case Q0: state = (c == 'a') ? Q1 : Q0; break;
            case Q1: state = (c == 'a') ? Q1 : Q2; break;
            case Q2: state = (c == 'a') ? Q3 : Q0; break;
            case Q3: state = (c == 'a') ? Q1 : Q4; break;
            case Q4: state = Q4; break;
        }
    }
    return state == Q4;
}


/*  PROBLEM 2 */
bool problem2(const string& s)
{
    enum State {
        Q0,
        Q1,
        Q2,
        Q3,
        Q4
    };

    static const State T[5][2] = {
          // 0,  1 = this our alphabet
        {Q0, Q1}, //q0
        {Q2, Q3}, //q1
        {Q4, Q0}, //q2
        {Q1, Q2}, //q3
        {Q3, Q4}, //q4
    };

    State state = Q0; // starting
    for (char c : s) {
        if (c != '0' && c != '1') return false;
        state = T[state][c - '0'];
    }
    return state == Q0; // final
}

/*  PROBLEM 3 */
enum State { Q0, Q1, Q2, Q3, Q4, Q5 };
enum Alphabet { DIGIT, SIGN, PERIOD, OTHER };

// this our alphabet
Alphabet classify(char c) {
    if (isdigit((unsigned char)c)) return DIGIT;
    if (c == '+' || c == '-')      return SIGN;
    if (c == '.')                  return PERIOD;
    return OTHER;
}

bool problem3(const string& s) {
    static const State T[6][4] = {
        //  digit, sign, period, other
        {   Q2,   Q1,     Q3,    Q5}, //q0
        {   Q2,   Q5,     Q3,    Q5}, //q1
        {   Q2,   Q5,     Q3,    Q5}, //q2
        {   Q4,   Q5,     Q5,    Q5}, //q3
        {   Q4,   Q5,     Q5,    Q5}, //q4
        {   Q5,   Q5,     Q5,    Q5}, //q5
    };
    State state = Q0; // starting
    for (char c : s) state = T[state][classify(c)];
    return state == Q2 || state == Q4; // final
}


int main() {

    cout << "Problem 1" << endl;
    for (string t : {"abab", "aabab", "abba", "bbababb", "aba"}) {
        cout << t << " -> " << (problem1(t) ? "accepted" : "rejected") << "\n";
    }

    cout << "Problem 2" << endl;
    for (string t : {"0", "101", "1010", "1111", "10011"}) {
        cout << t << " -> " << (problem2(t) ? "accepted" : "rejected") << "\n";
    }

    cout << "Problem 3" << endl;
    for (string t : {"42", "-3.14", "+.5", "5.", "4.0", "--1", "1.2.3", "abc"}) {
        cout << t << " -> " << (problem3(t) ? "accepted" : "rejected") << "\n";
    }
}










