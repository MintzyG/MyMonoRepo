fn main() {
    // A type annotated variable
    let logical: bool = true;

    let a_float: f64 = 3.14; // regularly annotated
    let an_integer = 5i32; // suffix annotated
    
    // Annotation is not needed, defaults will be used

    let default_float = 5.21; // f64
    let default_int = 1; // i32

    // Variables are constant by default
    // You can set them to mutable using mut
    let mut mutable = 1;
    mutable = 2;
    // The type of a variable can't be changed
    // mutable = true; -> ERROR!
    // Variables can be overwritten with shadowing
    let mutable = true;

    // Types can be inferred
    let mut inferred_type = 3; // Type i64 inferred from the line below
    inferred_type = 4294967296i64;

    println!("{}, {}, {}, {}, {}, {}, {}", logical, a_float, an_integer, default_float, default_int, mutable, inferred_type);

}
