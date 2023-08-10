// 11052 카드 구매하기
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Map{
public:
    int x, y;
    int dis;

    void setMap(int y, int x){
        this->y = y;
        this->x = x;
        dis = 101;
    }
};

vector<Map> home;
vector<Map> chicken;
vector<Map> selected;
vector<int> ans;
int N, M;



void dfs(int value, int count){
    int tempDis;
    int tempSum = 0;

    if(count == M){
        for(int j = 0; j<home.size(); j++){
            home[j].dis = 101;  // Dis 초기화
        }

        for(int i = 0; i < selected.size(); i++){
            for(int j = 0; j<home.size(); j++){
                tempDis = abs(selected[i].y - home[j].y) + abs(selected[i].x - home[j].x);

                if(home[j].dis > tempDis){
                    home[j].dis = tempDis;
                }
                tempSum += home[j].dis;
            }
            ans.push_back(tempSum);
            tempSum = 0;
        }

        return;
        
    }else{
        for(int i = value; i < chicken.size(); i++){
            selected.push_back(chicken[i]);
            dfs(i+1, count + 1);
            selected.pop_back();
        }
    }
}




int main(){
    cin >> N >> M;

    int value;
    Map temp;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> value;
            if(value == 1){          // home
                temp.setMap(i, j);
                home.push_back(temp);
            }else if(value == 2){       // chicken
                temp.setMap(i, j);
                chicken.push_back(temp);
            }
        }
    }

    dfs(0, 0);

    cout<<*min_element(ans.begin(), ans.end());
}