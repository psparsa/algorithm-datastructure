const sieveOfEratosthenes = (n: number) => {
  const numbers: Array<number | null> = [...Array(n - 1)].map(
    (_, idx) => idx + 2
  );

  for (let p = 0; p < n - 1; ++p)
    if (typeof numbers[p] === "number")
      for (let h = p + 2, x = h; x * h <= n; ++x) numbers[x * h - 2] = null;

  return numbers.filter((x) => typeof x === "number");
};

console.log("n:", 100, "\n");
console.log("Result:", sieveOfEratosthenes(100));
