fn binary_search<T: Ord>(list: &[T], target: T, first: usize, end: usize) -> Option<usize> {
    if first > end {
        return None;
    };

    let middle = (end - first) / 2 + first;
    if list[middle] == target {
        return Some(middle);
    }
    if target < list[middle] {
        return binary_search(list, target, first, middle - 1);
    }
    if target > list[middle] {
        return binary_search(list, target, middle + 1, end);
    }
    return None;
}

fn main() {
    let test_array = [1, 6, 7, 10, 16, 18, 23, 27, 47, 73, 89, 90, 100, 744];
    let target = 89;
    let test_array_len = test_array.len() - 1;
    println!("binary search input: {:?}", test_array);
    let binary_search_result = binary_search(&test_array, target, 0, test_array_len);
    println!("binary search result: {:?}", binary_search_result);
}