type OddEvenSortParams = {
  list: number[];
};

const oddEvenSort = ({ list }: OddEvenSortParams) => {
  const arrCpy = list.slice();
  const length = arrCpy.length;
  let isSorted = false;

  const chk = (idx: number) => {
    if (arrCpy[idx] > arrCpy[idx + 1]) {
      [arrCpy[idx], arrCpy[idx + 1]] = [arrCpy[idx + 1], arrCpy[idx]];
      isSorted = false;
    }
  };

  while (!isSorted) {
    isSorted = true;
    for (let oddIndex = 1; oddIndex < length - 2; oddIndex = oddIndex + 2)
      chk(oddIndex);
    for (let evenIndex = 0; evenIndex < length - 1; evenIndex = evenIndex + 2)
      chk(evenIndex);
  }

  return arrCpy;
};

const list = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0];
console.log("Input:", list);
console.log("Output:", oddEvenSort({ list }));
