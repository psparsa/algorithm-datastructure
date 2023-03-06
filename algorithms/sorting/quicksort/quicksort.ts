type DivideArray = ({ arr, pivot }: { arr: number[]; pivot: number }) => {
  lowerValues: number[];
  higherValues: number[];
};
const divideArray: DivideArray = ({ arr, pivot }) => {
  const lowerValues: number[] = [];
  const higherValues: number[] = [];

  arr.forEach((val) => {
    if (val <= pivot) lowerValues.push(val);
    else higherValues.push(val);
  });

  return {
    lowerValues,
    higherValues,
  };
};

type QuickSort = (arr: number[]) => number[];
const quickSort: QuickSort = (arr) => {
  const arrLength = arr.length;
  if (arrLength === 1) return arr;

  const arrWitoutPivot = arr.slice(0, arrLength - 1);
  const pivot = arr[arrLength - 1];
  const { lowerValues, higherValues } = divideArray({
    arr: arrWitoutPivot,
    pivot,
  });

  const resultFilter = (section: number[]) =>
    section.length > 1 ? quickSort(section) : section;

  return [...resultFilter(lowerValues), pivot, ...resultFilter(higherValues)];
};

const arr = [
  46, 61, 73, 93, 23, 64, 37, 93, 23, 62, 62, 13, 1, 6, 81, 7, 2, 9, 18, 643,
];
const result = quickSort(arr);

console.log("Array:", arr);
console.log("Sorted Array:", result);
