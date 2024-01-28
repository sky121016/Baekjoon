// 15686
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

class Node{
public:
    int x, y;
    int dis;

    int value;
    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;

        dis = 101;
    }
};

int n, m;
vector<Node> chicken;
vector<Node> home;
vector<Node> selected;
vector<int> result;

int tempDis = 101;
int totalDis;

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i<home.size(); i++){
            home[i].dis = 101;
        }

        for(int i = 0; i<selected.size(); i++){
            for(int j = 0; j<home.size(); j++){
                tempDis = abs(selected[i].x - home[j].x) + abs(selected[i].y - home[j].y);

                if(tempDis < home[j].dis){
                    home[j].dis = tempDis;
                }
                totalDis += home[j].dis;
            }
            result.push_back(totalDis);
            totalDis = 0;
        }
     
        return ;

    }else{
        for(int i = idx; i<chicken.size(); i++){
            selected.push_back(chicken[i]);
            dfs(i + 1, cnt + 1);
            selected.pop_back();

        }
    }


}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int temp;
    Node tempNode;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            if(temp == 1){
                tempNode.setNode(i, j, temp);
                home.push_back(tempNode);
            }else if(temp == 2){
                tempNode.setNode(i, j, temp);
                chicken.push_back(tempNode);
            }
        }    
    }

    dfs(0, 0);

    cout << *min_element(result.begin(), result.end());
}

