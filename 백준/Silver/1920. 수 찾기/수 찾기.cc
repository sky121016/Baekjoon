// 1920
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int> A;

int search(int num, int l, int r){
    int mid;

    while(l <= r){
        mid = (l + r) / 2;

        if(A[mid] < num){
            l = mid + 1;
        }else if(A[mid] > num){
            r = mid - 1;
        }else{
            return 1;
        }
    }

    return 0;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int temp;

    for(int i = 0; i<N; i++){
        cin >> temp;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());

    cin >> M;
    for(int j = 0; j<M; j++){
        cin >> temp;
        cout << search(temp, 0, N-1) << "\n";
    }
}
