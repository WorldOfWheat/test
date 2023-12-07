use std::io;

fn next_space(str: &String, current_index: usize) -> usize {
    let str_len = str.len();
    let sliced = &str[current_index..str_len];
    let bytes = sliced.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;            
        }
    }

    0
}

fn grep_second_word(str: &String) -> &str {
    let first_space = next_space(&str, 0);
    let second_space = next_space(&str, first_space+1);
    let sliced = &str[first_space+1..=first_space+second_space];
    &sliced
}

fn main() {
    let mut user_input = String::new();
    io::stdin()
        .read_line(&mut user_input);
    user_input.push(' ');

    let second_word = grep_second_word(&user_input);
    println!("{second_word}");
}
