<?php

function oddEvenSort($l)
{
    $lc = array_replace([], $l);
    $s = false;
    while (!$s) {
        $s = true;
        for ($i = 1; $i < count($lc) - 2; ++$i)
            if ($lc[$i] > $lc[$i + 1]) {
                $tmp = $lc[$i];
                $lc[$i] = $lc[$i + 1];
                $lc[$i + 1] = $tmp;
                $s = false;
            }
        for ($i = 0; $i < count($lc) - 1; ++$i)
            if ($lc[$i] > $lc[$i + 1]) {
                $tmp = $lc[$i];
                $lc[$i] = $lc[$i + 1];
                $lc[$i + 1] = $tmp;
                $s = false;
            }
    }

    return $lc;
}

$list = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0];

echo "Input:\n";
print_r($list);

echo "\n";

echo "Output:\n";
print_r(oddEvenSort($list));