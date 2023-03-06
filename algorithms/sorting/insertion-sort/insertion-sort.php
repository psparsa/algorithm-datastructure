<?php

function getTestArray($len)
{
    $tmpArr = range(0, $len - 1);
    shuffle($tmpArr);
    return $tmpArr;
}

function shouldSwap($a, $b, $dir)
{
    return $dir === "ASC" ? $a > $b : $a < $b;
}

function swap($keyA, $keyB, $arr)
{
    $tmpArr = array_replace([], $arr);
    [$tmpArr[$keyA], $tmpArr[$keyB]] = [$tmpArr[$keyB], $tmpArr[$keyA]];

    return $tmpArr;
}

function insertionSort($arr, $dir)
{
    $cpyArr = array_replace([], $arr);
    $arrLength = count($cpyArr);

    if ($arrLength <= 1) return $cpyArr;

    for ($j = 1; $j < $arrLength; $j++) {
        $currentVal = $cpyArr[$j];
        $prevPointer = $j - 1;

        while (
            $prevPointer >= 0 && shouldSwap($cpyArr[$prevPointer], $currentVal, $dir)
        ) {
            $cpyArr = swap($prevPointer, $prevPointer + 1, $cpyArr);
            --$prevPointer;
        }
    }

    return $cpyArr;
}

$testArray = getTestArray(20);

echo "Input:\n";
print_r($testArray);

echo "\n";

echo "Output:\n";
print_r(insertionSort($testArray, "ASC"));
