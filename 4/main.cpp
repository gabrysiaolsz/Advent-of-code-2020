#include <iostream>

using namespace std;

bool find(string s, string word) {
    size_t found = s.find(word);
    if (found != string::npos)
        return 1;
    else
        return 0;
}

int first() {
    int final_res = 0;

    while (!cin.eof()) {
        string line;
        int res = 0;
        while (getline(cin, line) && !line.empty()) {
            if (find(line, "byr")) res++;
            if (find(line, "iyr")) res++;
            if (find(line, "eyr")) res++;
            if (find(line, "hgt")) res++;
            if (find(line, "hcl")) res++;
            if (find(line, "ecl")) res++;
            if (find(line, "pid")) res++;
        }
        if (res == 7) final_res++;
        res = 0;
    }
    cout << endl;
    return final_res;
}

int find1(string s, string word) {
    size_t found = s.find(word);
    if (found != string::npos)
        return found;
    else
        return -1;
}

int second() {
    int final_res = 0;

    while (!cin.eof()) {
        string line;
        int res = 0;
        while (getline(cin, line) && !line.empty()) {
            if (find1(line, "byr") != -1) {
                int year = 0;

                year += 1000 * (int) (line[find1(line, "byr") + 4] - '0');
                year += 100 * (int) (line[find1(line, "byr") + 5] - '0');
                year += 10 * (int) (line[find1(line, "byr") + 6] - '0');
                year += (int) (line[find1(line, "byr") + 7] - '0');
                if (year >= 1920 && year <= 2002) {
                    res++;
                }
            }
            if (find1(line, "iyr") != -1) {
                int year = 0;

                year += 1000 * (int) (line[find1(line, "iyr") + 4] - '0');
                year += 100 * (int) (line[find1(line, "iyr") + 5] - '0');
                year += 10 * (int) (line[find1(line, "iyr") + 6] - '0');
                year += (int) (line[find1(line, "iyr") + 7] - '0');

                if (year >= 2010 && year <= 2020)
                    res++;
            }
            if (find1(line, "eyr") != -1) {
                int year = 0;

                year += 1000 * (int) (line[find1(line, "iyr") + 4] - '0');
                year += 100 * (int) (line[find1(line, "iyr") + 5] - '0');
                year += 10 * (int) (line[find1(line, "iyr") + 6] - '0');
                year += (int) (line[find1(line, "iyr") + 7] - '0');

                if (year >= 2020 && year <= 2030)
                    res++;
            }
            if (find1(line, "hgt") != -1) {
                int h = 0;

                if (line[find1(line, "hgt") + 7] == 'c')//mamy cm
                {
                    h = 0;
                    h += 100 * (int) (line[find1(line, "hgt") + 4] - '0');
                    h += 10 * (int) (line[find1(line, "hgt") + 5] - '0');
                    h += (int) (line[find1(line, "hgt") + 6] - '0');
                    if (h >= 150 && h <= 193)
                        res++;
                } else//in
                {
                    h = 0;
                    h += 10 * (int) (line[find1(line, "hgt") + 4] - '0');
                    h += (int) (line[find1(line, "hgt") + 5] - '0');
                    if (h >= 59 && h <= 76)
                        res++;
                }
            }
            if (find1(line, "hcl") != -1) {
                if (line[find1(line, "hcl") + 4] == '#') {
                    int help = 0;
                    for (int i = 5; i < 11; i++) {
                        if (isdigit(line[find1(line, "hcl") + i]) ||
                            isalpha(line[find1(line, "hcl") + i]))
                            help++;
                    }
                    if (help == 6) {
                        res++;
                    }
                }
            }
            if (find1(line, "ecl") != -1) {
                char c0 = line[find1(line, "hcl") + 4];
                char c1 = line[find1(line, "hcl") + 5];
                char c2 = line[find1(line, "hcl") + 6];

                if (c0 == 'a' && c1 == 'm' && c2 == 'b')
                    res++;
                if (c0 == 'b' && c1 == 'l' && c2 == 'u')
                    res++;
                if (c0 == 'b' && c1 == 'r' && c2 == 'n')
                    res++;
                if (c0 == 'g' && c1 == 'r' && c2 == 'y')
                    res++;
                if (c0 == 'g' && c1 == 'r' && c2 == 'n')
                    res++;
                if (c0 == 'h' && c1 == 'z' && c2 == 'l')
                    res++;
                if (c0 == 'o' && c1 == 't' && c2 == 'h')
                    res++;
            }
            if (find1(line, "pid") != -1) {
                int help = 0;
                for (int i = 4; i < 13; i++) {
                    if (isdigit(line[find1(line, "hcl") + i]))
                        help++;
                }
                if (help == 9) {
                    res++;
                }
            }
        }
        if (res == 7) final_res++;
        res = 0;
    }
    cout << endl;
    return final_res;
}

int main() {

    cout << first() << endl;
    cout << second() << endl;

    return 0;
}
