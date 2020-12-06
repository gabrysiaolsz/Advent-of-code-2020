#include <iostream>
using namespace std;

int next(int curr, int size, int add)
{
    int next = curr+add;
    if(next > size-1)
        next -= size;
    return next;
}
int first(string line)
{
    int res = 0;
    int curr = 0;

    while(!cin.eof())
    {
        cin>>line;
        cin>>line;
        curr = next(curr, line.size(), 1);

        if(line[curr] == '#')
            res++;
    }
    return res;
}

int main()
{
    string line;
    cin>>line;
    cout<<first(line)<<endl;

    return 0;
}
