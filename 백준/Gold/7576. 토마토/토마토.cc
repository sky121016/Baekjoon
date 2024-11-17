// 7576 토마토
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Box{
public:
    int x,y;
    int hasTomato;          // -1, 0, 1

    void setBox(int y, int x){
        this->x = x;
        this->y = y;
    }
};

int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};


int m,n;
Box box[1001][1001];        
int result;
// vector<int> day[1001];
int day[1001][1001] ={0};





bool canVisit(int ny, int nx){
    return (box[ny][nx].hasTomato == 0 && nx >= 0 && nx < m && ny >= 0 && ny < n);
}


bool notFinished(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(box[i][j].hasTomato == 0 && day[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

int max(){
    int max = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(max<day[i][j]){
                max = day[i][j];
            }
        }
    }
    return max;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<Box> q;

    cin>>m>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            box[i][j].setBox(i, j);
            cin >> box[i][j].hasTomato;

            if(box[i][j].hasTomato == 1){           // 처음부터 토마토
                q.push(box[i][j]);
            }
        }
    }

 
    
      
    Box b;

    int nx, ny;
    int visited[1001][1001] = {0};

    while(!q.empty()){
        b = q.front();
        visited[b.y][b.x] = true;
        q.pop();

        for(int i = 0; i<4; i++){
            ny = b.y + dir[i][0];
            nx = b.x + dir[i][1];

            if(!visited[ny][nx] && canVisit(ny, nx)){
                if(day[ny][nx] != 0 && day[ny][nx] > day[b.y][b.x]+1){
                    day[ny][nx] = day[b.y][b.x]+1;     
                }else if(day[ny][nx] == 0){
                    day[ny][nx] = day[b.y][b.x]+1;                
                }
                visited[ny][nx] = true;
                q.push(box[ny][nx]);
            }
        }
    }


    if(q.size() == m*n){
        result = 0;
    }else if(notFinished()){
        result = -1;
    }else{
        result = max();
    }

    cout<<result<<"\n";

}

