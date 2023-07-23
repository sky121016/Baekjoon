//1806 부분합
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int s;
int sum;
int arr[100001];
vector<int> length;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> s;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    sum = arr[0];

    int l;
    int left = 0, right = 0;

    while (left <= right && right < n){
        if(sum >= s){
            l = right - left + 1;       // 길이 저장
            length.push_back(l);

            sum -= arr[left];           
            left++;

        }else{
            right++;
            sum += arr[right];
        }
    }

    if(length.empty()){
        cout<<"0";
    }else{
        cout<<*min_element(length.begin(), length.end());
    }
}
