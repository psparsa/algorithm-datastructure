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

function bubbleSort($arr, $dir)
{
    $cpyArr = array_replace([], $arr);
    $arrLength = count($cpyArr);

    for ($x = 0; $x < $arrLength; $x++)
        for ($y = 0; $y < ($arrLength - 1 - $x); $y++) {
            $currentVal = $cpyArr[$y];
            $nextVal = $cpyArr[$y + 1];
            if (shouldSwap($currentVal, $nextVal, $dir)) {
                $cpyArr = swap($y, $y + 1, $cpyArr);
            }
        }

    return $cpyArr;
}

$testArray = getTestArray(20);

echo "Input:\n";
print_r($testArray);

echo "\n";

echo "Output:\n";
print_r(bubbleSort($testArray, "ASC"));
