use std::env;
use std::time::SystemTime;
use getrandom::getrandom;
use std::process::exit;
use std::fs::{File, metadata, rename, read_link, remove_file, soft_link, write, create_dir, remove_dir};
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

    let path1 = "/tmp/rust-wasi-a";
    let path2 = "/tmp/rust-wasi-b";
    let path3 = "/tmp/rust-wasi-c";
    write(path1, "test").unwrap();
    rename(path1, path2).unwrap();

    soft_link(path2, path3).unwrap();
    // TODO: requires resolving relative path in path_filestat_get
    // println!("Link: {:?}", read_link(path3).unwrap());

    remove_file(path2).unwrap();
    remove_file(path3).unwrap();

    let dir_path = "/tmp/rust-wasi";
    create_dir(dir_path).unwrap();
    remove_dir(dir_path).unwrap();

    exit(0);
}
