// 1162
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


class Node{
public:
    int num;
    long long w;
    int cnt;

    void setNode(int num, long long w, int cnt){
        this->num = num;
        this->w = w;
        this->cnt = cnt;
    }

    const bool operator < (const Node& b) const{
        return this->w < b.w;
    }
};

int n, m, k;
long long dist[10001][21];
vector< pair<int, long long> > edge[50001];         // w, city num
long long inf = 9223372036854775807;
long long ans;

void shortest(){
    priority_queue< Node > pq;
    Node u;
    u.setNode(1, 0, 0);
    pq.push(u);

    Node s;
    while(!pq.empty()){
        s = pq.top();
        pq.pop();

        int cur = s.num;
        int cnt = s.cnt;
        long long w = -s.w;


        if(dist[cur][cnt] < w){
            continue;
        }


        for(int i = 0; i<edge[cur].size(); i++){
            int next = edge[cur][i].first;
            long long nextw = edge[cur][i].second;


            Node v;

            // 포장 X
            if(dist[next][cnt] > nextw + w){
                v.setNode(next, -(nextw + w), cnt);
                pq.push(v);
                dist[next][cnt] = nextw + w;
            }

            // 포장
            if(cnt < k && dist[next][cnt+1] > w){
                // nextw는 안 더함 이전 w만 가져가기
                v.setNode(next, -w, cnt+1);      
                pq.push(v);
                dist[next][cnt+1] = w;
            }

            

        }
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    int a, b;
    long long c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

   for(int i = 2; i<=n; i++){
        for(int j = 0; j<21; j++){
            dist[i][j] = inf;
        }
    }

    shortest();


    ans = inf;
    for(int j = 1; j<=k; j++){
        ans = min(ans, dist[n][j]);
    }

    cout<<ans;

}

