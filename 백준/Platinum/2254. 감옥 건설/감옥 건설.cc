

// 2254
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>

using namespace std;

int n;
int nxt;
int first, second;
int start;
long long checkCCW;
bool isInside;
int cnt;

class Point{
public:
    int x, y;
    int p, q;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
        p = 0;
        q = 0;
    }
    void setPoint(int x, int y){
        this->x = x;
        this->y = y;
        p = 0;
        q = 0;
    }

    bool operator <(const Point& B) const {
        if(1LL * q * B.p != 1LL * p * B.q){
            return 1LL * q * B.p < 1LL * p * B.q;
        }
        if(y != B.y){
            return y < B.y;
        }
        return x < B.x;
    }
};

vector<Point> v;
Point prison;

long long ccw(int ax, int ay, int bx, int by, int cx, int cy){
    long long result = 1LL * (bx - ax) * (cy - ay) - 1LL * (cx - ax) * (by - ay);
    if(result< 0){
        return -1;
    }else if(result == 0){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> n >> x >> y;
    prison.setPoint(x, y);

    for(int i = 0; i<n; i++){
        cin >> x >> y;
        v.push_back(Point(x, y));
    }

    while(1){
        sort(v.begin(), v.end());

        for(int i = 1; i<v.size(); i++){
            v[i].p = v[i].x - v[0].x;
            v[i].q = v[i].y - v[0].y;
        }

        sort(v.begin()+1, v.end());

        vector<Point> v2 = v;
        stack<int> s, backup;
        s.push(0);
        s.push(1);

        nxt = 2;

        while(nxt < v.size()){
            while(s.size() >= 2){
                second = s.top();
                s.pop();
                first = s.top();

                if(ccw(v[first].x, v[first].y,  v[second].x, v[second].y,  v[nxt].x, v[nxt].y) > 0){
                    s.push(second);
                    break;
                }
            }
            s.push(nxt++);
        }

        backup = s;

        start = s.top();
        first = s.top();
        s.pop();
        second = s.top();
        s.pop();

        checkCCW = ccw(v[first].x, v[first].y,  v[second].x, v[second].y,  prison.x, prison.y);

        isInside = true;

        while(!s.empty()){
            first = second;
            second = s.top();
            s.pop();

            if(checkCCW != ccw(v[first].x, v[first].y,  v[second].x, v[second].y,  prison.x, prison.y)){
                isInside = false;
                break;
            }
        }

        if(checkCCW != ccw(v[second].x, v[second].y,  v[start].x, v[start].y,  prison.x, prison.y)){
            isInside = false;
        }

        if(isInside){
            cnt++;

            set<int> newV;
            for (int i = 0; i < v.size(); i++){
                newV.insert(i);
            }
            
            while(!backup.empty()) {
                newV.erase(backup.top());
                backup.pop();
            } 

            v.clear();

            for(auto iter = newV.begin(); iter != newV.end(); iter++){
                v.push_back(v2[(*iter)]);
            }

        }else{
            break;
        }

        if(v.size() <= 2){
            break;
        }


    }


    cout<<cnt;
}

