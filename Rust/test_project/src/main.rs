use std::io;
use rand::Rng;

fn main() {
    let rand_number = rand::thread_rng().gen_range(1..=500);
    println!("{rand_number}");

    let mut guess = String::new();
    io::stdin().read_line(&mut guess)
        .expect("Failed to read line");
    println!("{guess}");
}