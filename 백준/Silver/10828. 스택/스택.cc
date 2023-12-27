// 10828
#include<iostream>
#include<string>
#include<vector>
using namespace std;
    
int n;
int cnt;
int num;
vector<int> arr;

int main(){
    cin >> n;


    string cmd;
    while(cnt < n){
        cin >> cmd;
        
        if(cmd == "push"){

            cin >> num;
            arr.push_back(num);

        } else if(cmd == "pop"){

            int size = arr.size();

            if(size <= 0){
                cout << "-1\n";
            }else{
                cout << arr[size - 1] << endl;
                arr.pop_back();
            }

        } else if(cmd == "size"){

            int size = arr.size();

            if(arr.empty()){
                cout << "0\n";
            }else{
                cout<<arr.size()<<endl;
            }

        } else if(cmd == "empty"){

            if(arr.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }

        } else if(cmd == "top"){
             
            int size = arr.size();

            if(arr.empty()){
                cout<<"-1\n";
            }else{
                cout<<arr[size-1]<<endl;
            }
            
        }

        cnt++;
    }
}