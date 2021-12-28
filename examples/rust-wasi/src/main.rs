use std::env;
use std::time::SystemTime;
use getrandom::getrandom;
use std::process::exit;

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("Arguments: {:?}", args);

    let environment: Vec<(String, String)> = env::vars().collect();
    println!("Environment: {:?}", environment);

    let now = SystemTime::now();
    println!("Now: {:?}", now);

    let mut r: [u8; 8] = [0; 8];
    getrandom(&mut r).unwrap();
    println!("Random: {:?}", r);

    exit(0);
}
