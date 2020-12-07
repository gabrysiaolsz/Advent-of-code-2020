#include <iostream>

using namespace std;

int first() {
    int sum = 0;
    int C[26] = {0};

    while (!cin.eof()) {
        string s;
        getline(cin, s);

        if (s.empty())//jak trafisz na pustą to zeruj
        {
            for (int i = 0; i < 26; i++) {
                if (C[i] == 1) {
                    sum++;
                    C[i] = 0;
                }
            }

        } else {
            for (int i = 0; i < s.size(); i++) {
                C[s[i] - 'a'] = 1;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (C[i] == 1) {
            sum++;
            C[i] = 0;
        }
    }

    return sum;
}

int second() {
    int sum = 0;
    int C[26] = {0};
    int num = 0;

    while (!cin.eof()) {
        string s;
        getline(cin, s);

        if (s.empty())//jak trafisz na pustą to zeruj
        {
            for (int i = 0; i < 26; i++) {
                if (C[i] == num) {
                    sum++;
                    cout << "sum " << sum << endl;
                }
                C[i] = 0;
            }

            num = 0;
        }

        else
        {
            num++;

            for (int i = 0; i < s.size(); i++) {
                C[s[i] - 'a']++;
            }
        }

    }

    return sum;
}

int main()
{
    //cout << first() << endl;
    cout << second() << endl;
    
    return 0;
}
