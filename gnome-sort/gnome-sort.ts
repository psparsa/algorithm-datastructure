const swap = (list: number[], i1: number, i2: number): number[] => {
  const tmp = list.slice();
  [tmp[i1], tmp[i2]] = [tmp[i2], tmp[i1]];
  return tmp;
};

type GnomeSort = (list: number[], pointer?: number) => number[];
const gnomeSort: GnomeSort = (list, pointer = 0) => {
  const listSize = list.length;
  const prevPointer = pointer - 1;
  const nextPointer = pointer + 1;

  if (listSize <= 1) return list;

  if (pointer > listSize - 1 || pointer < 0) throw Error();
  if (pointer === 0) return gnomeSort(list, nextPointer);
  if (pointer === listSize - 1) return list;

  if (list[pointer] < list[prevPointer])
    return gnomeSort(swap(list, pointer, prevPointer), prevPointer);
  return gnomeSort(list, nextPointer);
};

const arr = Object.freeze([23, 73, 1, 3, 71, 10, 16, 63, 125, 52, 156, 22]);
const res = gnomeSort(arr.slice(), 1);

console.log("Dataset:", arr);
console.log("Result:", res);
