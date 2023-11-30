#![allow(unused_variables)]
#![allow(unused_assignments)]
fn main() {

    // Scalar Types

    // Signed integers
    // i8, i16, i32, i64, i128 and isize
    // Unsigned integers
    // u8, u16, u32, u64, u128, usize
    // Floats
    // f32, f64
    // char -> 4 bytes long
    // bool -> true or false
    // () -> this is an unit type whose only possible value is an empty tuple

    // Compound Types

    // Arrays [1, 2, 3]
    // Tuples (1, true)

    // Variables can be type annotated
    let logic: bool = true; // regular annotation
    let a_float: f64 = 1.0; // ...
    let an_int = 5i32; // Suffix annotation

    // Defaults can be used
    let default_float = 3.0; // f64
    let default_int = 7; // i32

    // Types can be inferred from context
    let mut inferred_type = 12; // Type i64 inferred from another line
    inferred_type = 4294967296i64;

    // A mutable variable's value can be changed
    let mut mutable = 12; // Mutable i32
    mutable = 21;

    // The type of a variable cannot be changed!
    // mutable = true; ERROR!
    // Tho, variables can be overwritten with shadowing
    let mutable = true;
    
    println!("{}, {}, {}, {}, {}", logic, a_float, an_int, default_int, default_float);
    println!("{}, {}", inferred_type, mutable);

    // With literals we need to suffix them with their type
    // Operators available are similar to C like languages
    println!("1 + 2 = {}", 1u32 + 2);
    println!("1 - 2 = {}", 1i32 - 2); // if we use u32 we can't do the operation
    println!("1e4 is {}, -2.5e-3 is {}", 1e4, -2.5e-3); // scientific notation
    // Integers can be expressed in other formats by prefixing 0b for binary 0o for oxtal and 0x for hexadecimal
    // Numbers prefixed by a specific numeral system have to be written in that number system
    // if you want to write them normally use formatting instead, like: {:b}, {:o}, {:x}
    println!("int {}, binary {}, octal {}, hexadecimal {}", 19i32, 0b01101i32, 0o2i32, 0x19i32);
    // The numbers above will be written in their integer form since their are suffixed by i32 
    println!("int {0}, binary {0:b}, octal {0:o}, hexadecimal {0:x}", 19);
    // Boolean logic
    println!("true AND false is {}", true && false);
    println!("true OR false is {}", true || false);
    println!("NOT true is {}", !true);
    // Bitwise operations
    println!("0011 AND 0101 is {:04b}", 0b0011u32 & 0b0101);
    println!("0011 OR 0101 is {:04b}", 0b0011u32 | 0b0101);
    println!("0011 XOR 0101 is {:04b}", 0b0011u32 ^ 0b0101);
    println!("1 << 5 is {}", 1u32 << 5);
    println!("0x80 >> 2 is 0x{:x}", 0x80u32 >> 2);
    // You can use underscores to improve readability
    println!("both {} and {} work with underscores", 1_000_000, 1.234_567_890);

    //TODO: add tuples arrays and slices
}
