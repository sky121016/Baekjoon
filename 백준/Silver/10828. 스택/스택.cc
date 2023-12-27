#include <iostream>
#include <string>

using namespace std;

int main()
{
    string command;             // 명령

    int size;                   // 명령의 수
    cin >> size;

    int top = 0;

    int arr[10000];             // 스택 배열
    

    for (int i = 0; i < size; i++){
        cin >> command;

        if (command == "push"){
            cin >> arr[top];
            top++;
        } 
        
        else if (command == "pop"){
            if (top > 0){
                top--;
                cout << arr[top] << endl;
            } else {
                cout<<"-1"<<endl;
            }
        } 
        
        else if (command == "size"){
            cout << top << endl;
        } 
        
        else if (command == "empty"){
            if (top == 0){
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
        
        else if (command == "top"){
            if (top>0){
                cout << arr[top-1] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}
