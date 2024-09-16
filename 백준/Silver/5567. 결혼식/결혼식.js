// 5567

const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "/input.txt")
  )
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.split(" ").map(Number));

const bfs = (V, friend, dis, visited) => {
  var q = [];

  q.push(V);

  var v;

  while (q.length) {
    v = q[0];

    q.shift();

    for (var i in friend[v]) {
      var next = friend[v][i];
      if (!visited[next]) {
        if (dis[next] > dis[v] + 1) {
          dis[next] = dis[v] + 1;
        }
        visited[next] = true;
        q.push(next);
      }
    }
  }
};

const main = () => {
  // var fs = require('fs');
  // var input = fs.readFileSync('input.txt').toString().trim().split('\n').map((el) => el.split(" ").map(Number));

  var n = input[0][0];
  var m = input[1][0];

  var a;
  var b;

  var friend = Array.from({ length: n + 1 }, () => []);
  var dis = Array(n + 1).fill(501);
  var visited = Array(n + 1).fill(false);

  for (var i = 0; i < m; i++) {
    a = input[i + 2][0];
    b = input[i + 2][1];

    friend[a].push(b);
    friend[b].push(a);
  }

  visited[1] = true;
  dis[1] = 0;

  bfs(1, friend, dis, visited);

  var cnt = 0;
  for (var i = 2; i <= n; i++) {
    if (dis[i] <= 2) {
      cnt++;
    }
  }

  console.log(cnt);
};

main();
