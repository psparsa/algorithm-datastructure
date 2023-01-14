function shellSort(arr: number[]) {
  const arrCpy = arr.slice();
  const length = arrCpy.length + 1;
  const f = Math.floor;

  let pointer = f(length / 2);
  while (pointer > 0) {
    for (let i = pointer; i < length - 1; i++) {
      let tmp = arrCpy[i];
      let y = i;
      for (; y >= pointer && arrCpy[y - pointer] > tmp; y = y - pointer)
        arrCpy[y] = arrCpy[y - pointer];
      arrCpy[y] = tmp;
    }
    pointer = f(pointer / 2);
  }

  return arrCpy;
}

const input = [9, 5, 2, -125, 5, 6, 1, -4, -6, 7, 214, 516, 103, 0, 13];
console.log("Input:", input, "\n");
console.log("Output:", shellSort(input));
