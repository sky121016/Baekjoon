// 1365

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

const [n, num] = input;
const sorted = [];

const BS = (x) => {
  var l = 0;
  var r = sorted.length - 1;
  var mid;

  while (l < r) {
    mid = (l + r) / 2;
    mid = parseInt(mid);

    if (x <= sorted[mid]) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  sorted[l] = x;
};

const main = () => {
  for (var x of num) {
    if (sorted.length == 0 || sorted[sorted.length - 1] < x) {
      sorted.push(parseInt(x));
    } else {
      BS(x);
    }
  }

  var ans = n - sorted.length;

  console.log(ans);
};

main();

