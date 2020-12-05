#include <iostream>

using namespace std;

int first()
{
    int from, to;
    int how_many, res = 0;
    char letter;
    string word, trash;


    while(!cin.eof()) {
        cin >> from >> to >> letter >> trash >> word;
        to = (-1) * to;
        how_many = 0;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == letter)
                how_many++;
        }
        if (how_many >= from && how_many <= to)
            res++;
    }
    return res;
}

int second()
{
    int from, to;
    int how_many, res = 0;
    char letter;
    string word, trash;


    while(!cin.eof()) {
        cin >> from >> to >> letter >> trash >> word;
        to = (-1) * to;
        how_many = 0;

        if(word[from-1] == letter) {
            how_many++;
        }
        if(word[to-1] == letter) {
            how_many++;
        }

        if (how_many == 1)
            res++;
    }
    return res;

}

int main() {

    //cout<<first()<<"\n";

    cout<<second()<<"\n";

    return 0;
}
