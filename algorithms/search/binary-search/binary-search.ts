const getSortedArray = (len: number) => [...Array(len)].map((_, i) => i + 1);

interface GetMiddleOfRangeParams {
  start: number;
  end: number;
}

const getMiddleOfRange = ({ start, end }: GetMiddleOfRangeParams) =>
  Math.ceil((end - start) / 2) + start;

interface BinarySearchParams {
  arr: number[];
  target: number;
  start?: number;
  end?: number;
}

const binarySearch = ({ arr, target, start, end }: BinarySearchParams) => {
  const arrLength = arr.length;
  const startP = start ?? 0;
  const endP = end ?? arrLength - 1;

  if (arrLength === 1) return arr[0] === target ? 0 : -1;

  const middle = getMiddleOfRange({ start: startP, end: endP });

  if (target === arr[middle]) return middle;
  if (target < arr[middle])
    return binarySearch({ arr, target, start: startP, end: middle - 1 });
  if (target > arr[middle])
    return binarySearch({ arr, target, start: middle + 1, end: endP });

  return -1;
};

const parseBinarySearchOutput = (position) =>
  position > -1 ? `The Value Positions is: ${position}` : `Nou Found!`;

const tmpArr = getSortedArray(10);
const answer = parseBinarySearchOutput(
  binarySearch({ arr: tmpArr, target: 8 })
);
console.log(answer);
