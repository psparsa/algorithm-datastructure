<?php
function getSortedArray($len)
{
    return range(0, $len - 1);
}

function getMiddleOfRange($start, $end)
{
    return ceil(($end - $start) / 2) + $start;
}

function binarySearch($arr, $target, $start = null, $end = null)
{
    $arrLength = sizeof($arr);
    $startPtr = $start ?? 0;
    $endPtr = $end ?? $arrLength;

    if ($arrLength < 2) return $arr;

    $middlePtr = getMiddleOfRange($startPtr, $endPtr);

    if ($arr[$middlePtr] === $target) return $middlePtr;
    if ($arr[$middlePtr] < $target) return binarySearch($arr, $target, $middlePtr + 1, $endPtr);
    if ($arr[$middlePtr] > $target) return binarySearch($arr, $target, $start, $middlePtr - 1);
    return -1;
}


$sortedArr = getSortedArray(10);
$result = binarySearch($sortedArr, 6);

echo $result;
