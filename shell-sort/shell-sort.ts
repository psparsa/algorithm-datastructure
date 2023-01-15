function shellSort(arr: number[], gap: number | null = null) {
  const length = arr.length + 1;
  if (gap === null) return shellSort(arr, ~~(length / 2));
  if (gap < 1) return arr;
  const arrCpy = arr.slice();
  for (let i = gap; i < length - 1; i++) {
    let tmp = arrCpy[i];
    let y = i;
    for (; y >= gap && arrCpy[y - gap] > tmp; y = y - gap)
      arrCpy[y] = arrCpy[y - gap];
    arrCpy[y] = tmp;
  }
  return shellSort(arrCpy, ~~(gap / 2));
}

const input = [9, 5, 2, -125, 5, 6, 1, -4, -6, 7, 214, 516, 103, 0, 13];
console.log("Input:", input, "\n");
console.log("Output:", shellSort(input));
