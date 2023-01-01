type FisherYatesShuffleParams = {
  list: unknown[];
  pointer?: number;
};

const fisherYatesShuffle = ({ list, pointer }: FisherYatesShuffleParams) => {
  if (pointer === undefined)
    return fisherYatesShuffle({ list, pointer: list.length - 1 });
  if (pointer < 1) return list;
  const randomIndex = Math.floor(Math.random() * (pointer + 1));
  const arr = list.slice();
  [arr[pointer], arr[randomIndex]] = [arr[randomIndex], arr[pointer]];
  console.log(pointer, randomIndex);
  return fisherYatesShuffle({ list: arr, pointer: pointer - 1 });
};

const aDummySortedList = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
console.log("Input: ", aDummySortedList);
console.log("output:", fisherYatesShuffle({ list: aDummySortedList }));
