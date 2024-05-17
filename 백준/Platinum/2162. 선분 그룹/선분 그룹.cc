// 2162
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector< pair<long long, long long> > p1;
vector< pair<long long, long long> > p2;
vector<long long> p;
vector<long long> unionSize;
int groupNum;

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long temp;
    temp = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
    if(temp < 0){
        return -1;
    }else if(temp > 0){
        return 1;
    }else{
        return 0;
    }
}

bool isSameGroup(int i, int j){
    long long x1 = p1[i].first;
    long long y1 = p1[i].second;
    long long x2 = p2[i].first;
    long long y2 = p2[i].second;

    long long x3 = p1[j].first;
    long long y3 = p1[j].second;
    long long x4 = p2[j].first;
    long long y4 = p2[j].second;

    long long ccw12 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
    long long ccw34 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);


    if (ccw12 == 0 && ccw34 == 0){
        if(p1[i] > p2[i]){
            swap(p1[i],p2[i]);
        }
        if(p1[j] > p2[j]){
            swap(p1[j], p2[j]);
        }


        if(p1[i]<=p2[j] && p1[j]<=p2[i]){
            return true;
        }else{
            return false;
        }   
    }

    if(ccw12<= 0 && ccw34<= 0){
        return true;
    }else{
        return false;
    }

    
}

int findSet(int x){
    if(p[x] == x){
        return p[x];
    }

    return p[x] = findSet(p[x]);
}


void makeUnion(int i, int j){   // i, j : 선분 번호

    i = findSet(i);
    j = findSet(j);


    p[j] = i;

    unionSize[i] += unionSize[j];
}

void createSet(int i){
    p.push_back(i);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    long long x1, y1, x2, y2;


    p.push_back(0);
    unionSize.push_back(0);
    p1.push_back(make_pair(0,0));
    p2.push_back(make_pair(0,0));

    for(int i = 1; i<=n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        p1.push_back(make_pair(x1, y1));
        p2.push_back(make_pair(x2, y2));
        createSet(i);
        unionSize.push_back(1);
    }



    for (int j = 1; j <= n; j++){
        for(int i = 1; i<j; i++){
            if(isSameGroup(i, j) && findSet(j) != findSet(i)){
                // make Union
                makeUnion(i, j);
            }
        }
    }

    for(int i = 1; i<= n; i++){
        if(findSet(i) == i){
            groupNum++;
        }
    }

    cout<<groupNum<<"\n";
    cout<<*max_element(unionSize.begin(), unionSize.end());
}

