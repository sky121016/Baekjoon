#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Room{
public:
    int s, t;
    bool operator <(Room& b){
        return this->s < b.s;
    }

    void setRoom(int s, int t){
        this->s = s;
        this->t = t;
    }
};

struct cmp{
    bool operator()(Room a, Room b){
        if(a.s == b.s){
            return a.t > b.t;
        }else{
            return a.s > b.s;
        }
    }
};
struct cmp2{
    bool operator()(Room a, Room b){
        if(a.t == b.t){
            return a.s > b.s;
        }else{
            return a.t > b.t;
        }
    }
};

int n;
Room room[200001];
int tempS, tempT;
Room cur;
Room Top;

priority_queue<Room, vector<Room>, cmp> pq;
priority_queue<Room, vector<Room>, cmp2> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> tempS >> tempT;
        room[i].setRoom(tempS, tempT);
        pq.push(room[i]);
    }

    ans.push(pq.top());
    pq.pop();

    while(!pq.empty()){

        cur = pq.top();
        pq.pop();

        Top = ans.top();
        
        if(Top.t <= cur.s){
            ans.pop();
            ans.push(cur);
        }else{
            ans.push(cur);
        }
    
    }

    cout << ans.size();
}