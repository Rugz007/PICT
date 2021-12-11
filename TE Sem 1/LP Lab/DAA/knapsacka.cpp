#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll knapSack(vector<pair<ll, ll>> pairs, ll W, ll n)
{
    if (n == 0 || W == 0)
        return 0;

    if (pairs[n - 1].first > W)
        return knapSack(pairs, W, n - 1);

    else
        return max(pairs[n - 1].second + knapSack(pairs, W - pairs[n - 1].first, n - 1), knapSack(pairs, W, n - 1));
}

int main()
{
    vector<pair<ll, ll>> pairs;
    ll weight, value;
    ll n, w;
    cout<<"ENTER NUMBER OF ELEMENTS : ";
    cin>>n;
    cout<<"ENTER MAXIMUM CAPACITY OF KNAPSACK : ";
    cin>>w;
    cout<<endl;
    for(ll i = 1; i <= n; i++)
    {
        cout<<"ENTER FOR "<<i<< " ELEMENT IN ORDER <WEIGHT, VALUE> : ";
        cin>>weight>>value;
        pairs.push_back(make_pair(weight, value));
    }

    time_t start, end;

    time(&start);
    cout<<"MAXIMUM VALUE OBTAINED : "<<knapSack(pairs, w, n);
    time(&end);
    
    double time_taken = double(end - start);
    
    cout << "\n\nTIME TAKEN BY PROGRAM : " << fixed
         << time_taken << setprecision(5);
    cout << " SEC " << endl;
    
    return 0;
}