const getRandomNumber = (max: number) => Math.round(Math.random() * (max * 10));
const getRandomArray = (size: number) =>
  [...Array(size)].map(() => getRandomNumber(size));

const swap = (indexA: number, indexB: number, arr: number[]): number[] => {
  const tmpArr = [...arr];
  [tmpArr[indexA], tmpArr[indexB]] = [tmpArr[indexB], tmpArr[indexA]];
  return tmpArr;
};

type DirectionType = "ASC" | "DESC";
const shouldSwap = (a: number, b: number, dir: DirectionType) =>
  dir === "ASC" ? a > b : a < b;

type InsertionSortType = (arr: number[], dir?: DirectionType) => any;
const insertionSort: InsertionSortType = (arr, dir = "ASC") => {
  let cpyArr = [...arr];
  const arrLength = cpyArr.length;

  if (arrLength <= 1) return cpyArr;

  for (let x = 1; x < arrLength; x++) {
    const currentVal = cpyArr[x];
    let prevPointer = x - 1;

    while (
      prevPointer >= 0 &&
      shouldSwap(cpyArr[prevPointer], currentVal, dir)
    ) {
      cpyArr = swap(prevPointer, prevPointer + 1, cpyArr);
      prevPointer--;
    }
  }

  return cpyArr;
};

const randomArr = getRandomArray(10);
console.log("Input: ", randomArr);
console.log("output:", insertionSort(randomArr, "ASC"));
