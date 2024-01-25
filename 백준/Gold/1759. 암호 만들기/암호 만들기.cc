// 1759
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int L, C;
char a[16];
vector<char> result;
int letterCnt[2];     // 모음 자음
int ansCnt;     
bool visited[16];
int temp;

int getLetterIndex(char c, int i){
    if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
        return 0;
    }else{
        return 1;
    }
}

void dfs(int index, int cnt){
    if(cnt == L){
        for(int i = 0; i<L; i++){
            cout<<result[i];
        }
        cout << "\n";

    }else{
        for(int i = index; i<C; i++){
            if(!visited[i]){
                temp = getLetterIndex(a[i], i);


                if (letterCnt[temp] > 0){

                    visited[i] = true;
                    letterCnt[temp]--;
                    result.push_back(a[i]);

                    dfs(i + 1, cnt + 1);

                    temp = getLetterIndex(a[i], i);
                    visited[i] = false;
                    letterCnt[temp]++;
                    result.pop_back();
                }
            }
             
        }
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for(int i = 0; i<C; i++){
        cin >> a[i];
    }

    sort(a, a + C);


    letterCnt[0] = L - 2;
    letterCnt[1] = L - 1;

    dfs(0, 0);

}

