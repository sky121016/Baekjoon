// 2473 세 용액
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
vector<long long> arr;
vector<long long> ans(3);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    long long temp;

    for(int i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    
    int s;
    int e;

    long long tempSum;
    long long sum = 3000000000;

    for(int i = 0; i<n-2; i++){    // arr[i] = 고정 값
        s = i + 1;
        e = n - 1;

        while(s < e){
            tempSum = arr[i] + arr[s] + arr[e];

            if (abs(sum) >= abs(tempSum)){
                sum = tempSum;

                ans[0] = arr[i];
                ans[1] = arr[s];
                ans[2] = arr[e];
            }

            if(tempSum > 0){
                e--;
            }else{
                s++;  
            }
        }
        
    }


    sort(ans.begin(), ans.end());

    for(int i = 0; i<3; i++){
        cout<<ans[i]<<" ";
    }
}