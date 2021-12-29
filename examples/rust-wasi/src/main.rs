use std::env;
use std::time::SystemTime;
use getrandom::getrandom;
use std::process::exit;
use std::fs::{File, metadata};
use std::io::{stdin, Read};

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("Arguments: {:?}", args);

    let environment: Vec<(String, String)> = env::vars().collect();
    println!("Environment: {:?}", environment);

    let now = SystemTime::now();
    println!("Now: {:?}", now);

    let mut random_data1: [u8; 8] = [0; 8];
    getrandom(&mut random_data1).unwrap();
    println!("Random: {:?}", random_data1);

    println!("Write something:");
    let mut buffer = String::new();
    stdin().read_line(&mut buffer).unwrap();
    println!("Read from stdin: {:?}", buffer);

    let random_path = "/dev/random";
    let mut random_data2: [u8; 8] = [0; 8];
    let mut random_file = File::open(random_path).unwrap();
    random_file.read(&mut random_data2).unwrap();
    println!("Read from {}: {:?}", random_path, random_data2);

    let root_path = "/";
    let root_file = File::open(root_path).unwrap();
    let root_metadata1 = root_file.metadata().unwrap();
    println!("Metadata of {} (via FD): {:?}", root_path, root_metadata1);

    let root_metadata2 = metadata(root_path).unwrap();
    println!("Metadata of {} (via path): {:?}", root_path, root_metadata2);

    exit(0);
}
