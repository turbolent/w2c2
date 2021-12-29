use std::env;
use std::time::SystemTime;
use getrandom::getrandom;
use std::process::exit;
use std::fs::File;
use std::io::{stdin, Read};

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

    println!("Write something:");
    let mut buffer = String::new();
    stdin().read_line(&mut buffer).unwrap();
    println!("Read from stdin: {:?}", buffer);

    let path = "/dev/random";
    let mut r2: [u8; 8] = [0; 8];
    let mut f = File::open(path).unwrap();
    f.read(&mut r2).unwrap();
    println!("Read from {}: {:?}", path, r2);

    exit(0);
}
