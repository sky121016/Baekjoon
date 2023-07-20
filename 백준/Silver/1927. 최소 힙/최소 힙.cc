// 1927 최소 힙
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> heap;
int n;
int x;
vector<int> ans;

void push(int e){

    
    heap.push_back(e);

    int curr = heap.size()-1;                     // 마지막 노드 - 1에서 시작


    while(curr != 1 && heap[curr/2] > e){           // curr이 루트노드가 아니고 부모가 e보다 클 때 
        heap[curr] = heap[curr/2];                  // 부모 노드를 현재 위치로 이동
        curr /= 2;
    }

    heap[curr] = e;

}

void pop(){
    
    if(heap.size() == 1){        // empty
        ans.push_back(0);
        return;
    }


    ans.push_back(heap[1]);     // min

    int last = heap[heap.size()-1];     // 마지막 노드
    

    int curr = 1;                     // 현재 위치 = 루트노드
    int child = 2;                    // 자식노드

    while(child <= heap.size()-1){
        if(child < heap.size()-1 && heap[child] > heap[child+1]){       // 자식 둘 중 더 작은 값 고르기
            child++;
        }

        if(last <= heap[child]){             // last가 자식보다 작으면 현재 위치(curr)에 last가 들어감
            break;
        }

        heap[curr] = heap[child];           // last가 child보다 크면 자식 노드를 위로 이동

        curr = child;
        child *= 2;
    }

    heap[curr] = last;          // 현재 위치에 last
    heap.pop_back();            // heap 사이즈 줄이기

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    heap.push_back(0);      // 노드 index 1부터 시작

    for(int i = 0; i<n; i++){
        cin>>x;
        if(x == 0){
            pop();
        }else{
            push(x);
        }
    }


    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }

    
}

