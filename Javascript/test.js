// return x plus y
const increment = function() {
    return function increment(x, y) {
        return x + y;
    }
}();
console.log(increment(2, 10)) // Print: 1024
