#include <bits/stdc++.h>
using namespace std;
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

void bellman_ford(vector<pair<pll, ll>> graph, ll distance_array[], ll vertices, ll edges) 
{     
    ll source; 
    cout<<"ENTER SOURCE VERTEX: ";     
    cin>>source; 
 
    forc(i, 0, vertices-1)         
        distance_array[i] = INF; 
    
    distance_array[source] = 0; 
    
    forc(i, 1, vertices-1) 
    {         
        forc(j, 0, edges-1) 
        {             
            ll source__ = graph[j].first.first;
            ll destination__ = graph[j].first.second;             
            ll weight__ = graph[j].second; 
             
            if (distance_array[source__] != INT_MAX && distance_array[source__] + weight__ < distance_array[destination__]) 
                
                distance_array[destination__] = distance_array[source__] + weight__; 
        } 
    }      
    
    forc(i, 0, edges-1) 
    {         
        ll source__ = graph[i].first.first;         
        ll destination__ = graph[i].first.second;         
        ll weight__ = graph[i].second;         
        if (distance_array[source__] != INT_MAX && distance_array[source__] + weight__ < distance_array[destination__]) 

        {             
            cout<<"NEGATIVE WEIGHT CYCLE DETECTED...!!\nRETURNING...!!";     return; 
        } 
    }      
    
    cout<<"VERTEX   DISTANCE FROM SOURCE VERTEX\n____________________________________\n\n"; 

    forc(i, 0, vertices-1) 
    {         
        cout<<"  "<<i<<"        "<<distance_array[i]<<"\n"; 
    } 
}  

int main() 
{ 
    //fastcin();     
    vector<pair<pll, ll>> graph;     
    ll vertices,edges;     
    cout<<"ENTER NUMBER OF VERTICES: ";     
    cin>>vertices;     
    cout<<"ENTER NUMBER OF EDGES: ";     
    cin>>edges; 
    ll distance_array[vertices];     
    cout<<"\n\n";     
    
    forc(i, 0, edges-1) 
    {         
        ll src, dest, weight;         
        cout<<"ENTER <SOURCE, DESTINATION, WEIGHT>: ";         
        cin>>src>>dest>>weight;         
        graph.pb(mp(mp(src, dest), weight)); 
    }      
    
    bellman_ford(graph, distance_array, vertices, edges); 
 
    return 0; 
} 
 
