/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct Edge{
    int to;
    ll d, r;
};

vector<vector<Edge>> g;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; ll d, r;
        cin >> u >> v >> d >> r;
        g[u].push_back({v, d, r});
    }

    if(n == 1){
        cout << "0 0\n";
        return 0;
    }

    vector<ll> dist(n+1, INF);
    vector<ll> risk(n+1, INF);
    dist[1] = 0;
    risk[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [dis_u, u] = pq.top();
        pq.pop();

        if(dis_u > dist[u]) continue;

        for(auto &e : g[u]){
            int v = e.to;
            ll nd = dis_u + e.d;
            ll nr = risk[u] + e.r;

            if(nd < dist[v]){
                dist[v] = nd;
                risk[v] = nr;
                pq.push({nd, v});
            }else if(nd == dist[v]){
                if(nr < risk[v]){
                    risk[v] = nr;
                    pq.push({nd, v});
                }
            }
        }
    }

    if(dist[n] == INF){
        cout << "-1 -1\n";
    }else{
        cout << dist[n] << " " << risk[n] << "\n";
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1E18;
struct edge{
    int to;
    ll d,r;
};
vector<vector<edge>> g;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n,m;
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++)
   {
      int u,v;
      ll d,r;
      cin>>u>>v>>d>>r;
      g[u].push_back({v,d,r});
   }
   if(n==1)
   {
    cout<<"0 0"<<endl;
    return 0;
   }
   vector<ll>dist(n+1,INF);
   vector<ll>risk(n+1,INF);
   priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
   pq.push({0,1});
   while(!pq.empty())
   {
    auto[dis_u,u]=pq.top();
    pq.pop();
    if(dis_u>dist[u])continue;
    for(auto &e:g[u])
    {
        int v=e.to;
        ll nd=dis_u+e.d;
        ll nr=risk[u]+e.r;
        if(nd<dist[v])
        {
            dist[v]=nd;
            risk[v]=nr;
            pq.push({nd,v});
        }
        else if(nd==dist[v])
        {
            if(nr<risk[v])
            {
                risk[v]=nr;
                pq.push({nd,v});
            }
        }
    }
   }
   if(dist[n]==INF)
   {
    cout<<"-1 -1"<<endl;
   }
   else{
    cout<<dist[n]<<" "<<risk[n]<<endl;
   }
   return 0;
}