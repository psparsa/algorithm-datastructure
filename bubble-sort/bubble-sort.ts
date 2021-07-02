const getRandomNumber = () => Math.round(Math.random() * 100);
const getRandomArray = (size: number) => [...Array(size)].map(getRandomNumber);

const swap = (indexA: number, indexB: number, arr: number[]): number[] => {
  const tmpArr = [...arr];
  [tmpArr[indexA], tmpArr[indexB]] = [tmpArr[indexB], tmpArr[indexA]];
  return tmpArr;
};

type DirectionType = "ASC" | "DESC";
const shouldSwap = (a: number, b: number, direction: DirectionType) =>
  direction === "ASC" ? a > b : a < b;

const bubbleSort: (numArr: number[], direction?: DirectionType) => any = (
  numArr,
  direction = "ASC"
) => {
  let cpyArr = [...numArr];
  const arrLength = cpyArr.length;

  cpyArr.forEach((_, index) => {
    for (let y = 0; y < arrLength - index - 1; y++)
      if (shouldSwap(cpyArr[y], cpyArr[y + 1], direction))
        cpyArr = swap(y, y + 1, cpyArr);
  });

  return cpyArr;
};

const randomArr = getRandomArray(10);
console.log("Input:", randomArr);
console.log("output:", bubbleSort(randomArr));
