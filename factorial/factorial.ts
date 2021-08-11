const factorial = (num) => (num === 1 ? num : num * factorial(num - 1));

const answer = factorial(10);
console.log(answer);
