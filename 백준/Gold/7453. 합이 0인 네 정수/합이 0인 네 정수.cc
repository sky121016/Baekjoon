// 7453 합이 0인 네 정수
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long A[4001], B[4001], C[4001], D[4001];
long long cnt;
int n;
long long sum;

vector<long long> AB;
vector<long long> CD;

long long zeroS, zeroE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            AB.push_back(A[i] + B[j]);          // A + B 모두 저장
            CD.push_back(C[i] + D[j]);          // C + D
        }
    }    

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long s = 0, e = n*n - 1;


    while(s < n*n && e >= 0){
        sum = AB[s] + CD[e];

        if(sum < 0){
            s++;
        }else if(sum > 0){
            e--;
        }else{                  // if sum == 0
            zeroS = 1;      // AB[s]와 같은 값이 몇 개 있는지 세기
            zeroE = 1;
            
            while(s+zeroS < n*n && AB[s] == AB[s + zeroS]){           // AB[s]와 다음 값이 같으면 ZeroS++
                zeroS++;
            }
            while(e-zeroE >= 0 && CD[e] == CD[e - zeroE]){
                zeroE++;
            }

            cnt += zeroS * zeroE;
            s += zeroS;
            e -= zeroE;

        }
    }



    cout<<cnt;
}

