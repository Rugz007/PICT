//Author: Ojas Kund

#include <bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define rforc(i,a,b)    for(ll i=(a);i>=(b);i--)
#define ll              long long int
#define ld              long double
#define MOD             1000000007
#define INF             1e18
#define endl            "\n"
#define pb              push_back
#define pll             pair<ll,ll>
#define mp              make_pair
#define forc(i,a,b)     for(ll i=(a);i<=(b);i++)

void fastcin()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll menu()
{
    ll choice; 
    cout<<endl<<"\n\n1. FRACTIONAL KNAPSACK USING GREEDY\n2. 0/1 KNAPSACK USING DP\n3. COMPARISON BETWEEN GREEDY AND DP APPROACH FOR 0/1 KNAPSACK\n\nENTER CHOICE : ";
    cin>>choice;

    return choice;
}

void fractionalKnapsack(vector<pll> pairs, ll w, ll n)
{
    vector<pair<double, ll>> ans;
    forc(i, 0, n-1)
    {
        ans.pb(mp((double)(pairs[i].second) / (double)(pairs[i].first), i)) ;
    }

    sort(ans.begin(), ans.end(), greater<>());

    cout<<endl;

    double tw = 0, tc = 0;
    ll i = 0;
    double count = 0;
    while(i<n)
    {
        
        if(pairs[ans[i].second].first + tw <= w)
        {
            tw += pairs[ans[i].second].first;
            tc += pairs[ans[i].second].second;
            i++;
        }

        else
        {
            double rew = w - tw;
            count = double(pairs[ans[i].second].first) / double(rew);
            double val = rew * ( (double)(ans[i].first) );
            tw += rew;
            tc += val;

            break;
        }
    }

    cout<<endl;
    cout<<"MAXIMUM VALUE THAT CAN BE ACHIEVED : "<<tc<<endl;

}

ll zeroOneKnapsack(vector<pll> pairs, ll W, ll n)
{
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    forc(i, 1, n) 
    {
        rforc(w, W, 0) 
        { 
            if (pairs[i - 1].ff <= w)
                dp[w] = max(dp[w], dp[w - pairs[i - 1].ff] + pairs[i - 1].ss);
        }
    }

    return dp[W];
}


ll greedyZeroOneKnapsack(vector<pll> pairs, ll w, ll n)
{
    vector<pair<double, ll>> ans;
    forc(i, 0, n-1)
    {
        ans.pb(mp((double)(pairs[i].second) / (double)(pairs[i].first), i)) ;
    }

    sort(ans.begin(), ans.end(), greater<>());

    cout<<endl;

    double tw = 0, tc = 0;
    ll i = 0;
    double count = 0;
    while(i<n)
    {
        if(pairs[ans[i].second].first + tw <= w)
        {
            tw += pairs[ans[i].second].first;
            tc += pairs[ans[i].second].second;  
        }
        i++;
    }

    cout<<endl;
    return tc;

}



void solve()
{
    char c = 'y';
    char mc = 'y';
    do
    {
        vector<pll> pairs;
        ll weight, value;
        ll n, w;
        cout<<"\n\nENTER NUMBER OF ELEMENTS : ";
        cin>>n;
        cout<<"ENTER MAXIMUM CAPACITY OF KNAPSACK : ";
        cin>>w;
        cout<<endl;
        forc(i, 1, n)
        {
            cout<<"ENTER FOR "<<i<< "th ELEMENT IN ORDER <WEIGHT, VALUE> : ";
            cin>>weight>>value;
            pairs.pb(mp(weight, value));
        }

        time_t g_start = 0, g_end = 0, d_start = 0, d_end = 0;
        double g_time_taken = 0, d_time_taken = 0;


        do
        {
            
            ll choice = menu();
            
            switch(choice)
            {
                case 1: fractionalKnapsack(pairs, w, n);
                        break;

                case 2: 
                        cout<<"MAXIMUM VALUE OBTAINED : "<<zeroOneKnapsack(pairs, w, n);
                        break;

                case 3: ll grc, dpc;       
                        grc = greedyZeroOneKnapsack(pairs, w, n);
                        dpc = zeroOneKnapsack(pairs, w, n);

                        cout<<"\n\nGREEDY APPROACH FOR 0/1 KNAPSACK'S VALUE : " << grc;
                        cout<<"\nDP APPROACH FOR 0/1 KNAPSACK'S VALUE : " << dpc;
                        if (grc <= dpc)
                            cout<<"\n\nGREEDY SOLUTION IS NOT ALWAYS OPTIMAL";
                        break;
                default: cout<<"\nWRONG CHOICE...!!";
            }
            cout<<"\n\nDO YOU WANT TO CONTINUE USING THE SAME DATA (Y/N) : ";
            cin>>c;
        } while(c == 'y' || c == 'Y');
        cout<<"DO YOU WANT TO CHANGE DATA (Y/N) : ";
        cin>>mc;
    } while (mc == 'y' || mc == 'Y');   
    cout<<"\n\nEXITTING...!!";
}

int main()
{
    //fastcin();
    
    solve();
    
    return 0;
}


