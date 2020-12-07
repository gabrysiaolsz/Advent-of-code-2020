#include <iostream>

using namespace std;

struct range {
    int f;
    int t;
};

range decide1(char a, range r) {
    int m = (r.f + r.t) / 2;

    if (a == 'F' || a == 'L') {
        r.t = m;
    } else {
        r.f = m+1;
    }

    return r;
}

int first_help(string a) {
    range r, s;

    r.f = 0;
    r.t = 127;
    s.f = 0;
    s.t = 7;

    for (int i = 0; i < 7; i++) {
        char b = a[i];
        r = decide1(b, r);
    }

    for(int i = 7; i < 10; i++)
    {
        char b = a[i];
        s = decide1(b, s);
    }

    return r.f * 8 + s.f;
}

int first()
{
    int max = -1;
    int h;

    while(!cin.eof())
    {
        string a;
        cin>>a;

        h = first_help(a);
        if(h > max)
            max = h;
    }
    return max;
}

range second_help(string a) {
    range r, s;

    r.f = 0;
    r.t = 127;
    s.f = 0;
    s.t = 7;

    for (int i = 0; i < 7; i++) {
        char b = a[i];
        r = decide1(b, r);
    }

    for(int i = 7; i < 10; i++)
    {
        char b = a[i];
        s = decide1(b, s);
    }

    range g;
    g.f = r.f;
    g.t = s.f;

    return g;
}

int second()
{
    int A[128][8] = {0};
    range g;

    while(!cin.eof())
    {
        string a;
        cin>>a;

        g = second_help(a);

        A[g.f][g.t] = -1;
    }

    int i = 1;
    bool end = false;
    while(i < 128 && !end)
    {
        int h = 0;
        for(int j = 0; j < 8; j++)
        {
            if (A[i][j] == 0)
                h++;
        }
        i++;
        if(h == 0)
            end = true;
    }

    for(int k = i; k < 127; k++)
    {
        for(int l = 0; l < 8; l++)
        {
            if(A[k][l] != -1)
                return k * 8 + l;
        }
    }

    return -1;
}


int main() {

    cout << first();
    cout << second();

    return 0;
}
