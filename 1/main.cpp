#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int first_task(vector<int> A, int sum)
{
    int first = 0;
    int last = A.size() - 1;

    while(first < last)
    {
        if(A[first] + A[last] == sum) {
            return A[first] * A[last];
        }
        else if(A[first] + A[last] < sum)
            first ++;
        else
            last--;
    }

    return -1;
}

int second_task(vector<int> A, int sum)
{
    int r, first;
    int last = A.size()-1;
    int sum2;
    for(int i = 0; i < A.size()-2; i++)
    {
        r = A[i];
        sum2 = sum - r;
        first = i+1;
        
        while(first < last)
        {
            if(A[first] + A[last] == sum2)
            {
                return A[first] * A[last] * r;
            }
            else if(A[first] + A[last] < sum2)
                first ++;
            else
                last--;
        }
    }
    return -1;
}

int main() {

    vector<int> A;
    int num;

    while(cin>>num)
    {
        A.push_back(num);
    }

    sort(A.begin(), A.end());

    cout<<"\n";
    cout<<first_task(A, 2020)<<"\n";
    cout<<second_task(A, 2020)<<"\n";

    return 0;
}
