<?php

function fisherYatesShuffle($l)
{
    $lc = array_replace([], $l);
    $pointer = count($lc) - 1;
    while ($pointer > 0) {
        $randomIndex = rand(0, $pointer);
        $tmp = $lc[$pointer];
        $lc[$pointer] = $lc[$randomIndex];
        $lc[$randomIndex] = $tmp;
        --$pointer;
    }
    return $lc;
}

$list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

echo "Sorted List:\n";
print_r($list);
echo "\n";
echo "Shuffled List:\n";
print_r(fisherYatesShuffle($list));
