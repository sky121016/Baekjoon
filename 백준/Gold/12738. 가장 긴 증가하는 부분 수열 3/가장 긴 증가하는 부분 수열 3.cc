// 12738
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

long long n;
long long A[1010101];
vector<long long> R;

void BS(long long num){
    long long l, r;
    long long m;


    if(R.size() == 0 || R[R.size()-1] < num){
        R.push_back(num);
    }else{
        l = 0;
        r = R.size() - 1;

        while(l<r){
            m = (l + r) / 2;

            if(num <= R[m]){
                r = m;
            }else{
                l = m + 1;
            }
        }
        R[l] = num;
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> A[i];
    }


    for(int i = 0; i<n; i++){
        BS(A[i]);
    }

    cout<<R.size();

}



