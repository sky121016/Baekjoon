#include<iostream>
#include<vector>
using namespace std;

int N, M, K;
long long tree[4000001];
long long num[1000001];

// init
long long init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = num[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// sum
long long sum(int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        return 0;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// change
void change(int start, int end, int node, int index, long long value) {
    if (start>index || end<index) {
        return;
    }
    if (start == index && end == index) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    change(start, mid, node * 2, index, value);
    change(mid + 1, end, node * 2 + 1, index, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;


    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    init(1, N, 1);


    int a, b;
    long long c;

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            change(1, N, 1, b, c);
        }
        else if (a == 2) {
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }
}
