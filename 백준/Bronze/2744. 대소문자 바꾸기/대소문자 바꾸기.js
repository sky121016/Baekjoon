// 2744
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
  .split("\n");

const s = input[0];
// console.log(s);
var ans = "";

for(var i = 0; i<s.length; i++){
    if(s[i].codePointAt() >= 'a'.codePointAt()){
        ans+=s[i].toLocaleUpperCase();
    }else{
        ans+=s[i].toLocaleLowerCase();
    }
}

console.log(ans);
