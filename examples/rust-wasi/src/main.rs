use std::env;
use std::time::SystemTime;
use getrandom::getrandom;
use std::process::exit;
use std::fs::*;
use std::io::*;

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

    let path1 = "/tmp/rust-wasi-a";
    let path2 = "/tmp/rust-wasi-b";
    let path3 = "/tmp/rust-wasi-c";
    write(path1, "test").unwrap();
    rename(path1, path2).unwrap();

    soft_link(path2, path3).unwrap();
    println!("Link: {:?}", read_link(path3).unwrap());

    let mut path2_file = File::open(path2).unwrap();
    let path2_metadata1 = path2_file.metadata().unwrap();
    println!("Metadata of {} (via FD): {:?}", path2, path2_metadata1);

    let path2_metadata2 = metadata(path2).unwrap();
    println!("Metadata of {} (via path): {:?}", path2, path2_metadata2);

    let mut path2_data: [u8; 3] = [0; 3];
    path2_file.read(&mut path2_data).unwrap();
    println!("Read from {}: {:?}", path2, path2_data);

    remove_file(path2).unwrap();
    remove_file(path3).unwrap();

    let dir_path = "/tmp/rust-wasi";
    create_dir(dir_path).unwrap();
    remove_dir(dir_path).unwrap();

    println!("{:?}", read_dir("/tmp").unwrap().collect::<Vec<Result<DirEntry>>>());

    exit(0);
}
