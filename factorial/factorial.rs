fn factorial(num: u64) -> u64 {
    return if num == 1 { num } else { factorial(num-1) * num };
}

fn main() {
    let result = factorial(6);
    println!("6! = {}", result);
}