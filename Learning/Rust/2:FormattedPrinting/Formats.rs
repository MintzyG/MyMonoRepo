// Priting is hanndled by macros in std:fmt some macros are:
// print! ; println! ; eprint! ; eprintln!
// eprint and eprintln are the same as other prints but tehy print out to stderr instead

fn main() {
    println!("This -> {} will be replaced with arguments, which will be stringfied", 2);

    // Positional arguments can be passed to '{x}' which determines which arguments the '{}' will use
    println!("{0} and {1} are in the right order, but order doesn't matter {1}, {0}", 32, 64);
    println!("Arguments can also be named: {Name} has {Age} years of age", Name="John", Age=32);
    println!("You can specify different formatting inside using ':' lets see: {0} {0:b} {0:o} {0:x}", 28);
    println!("We can right of left justify text with '>' or '<' followed by a number {0:>5}, {0:<5}, see?", 3);
    println!("If we justify with a zero before the character we can pad the number {0:0>5}, {0:0<5}", 53);
    println!("You can use named arguments inside the format specifier by appending '$' {number:0>width$} ", number=32, width=8);

    // This macro allows code that would be removed by the compiler to keep existing
    #[allow(dead_code)]
    struct Structure(i32);
    // println!("This struct '{}' will not print!", Structure(3));
    // This will not compile because 'Structure' does not implement fmt::Display
    // and only types that implement fmt::Display can be formatted with '{}'
    // User defined types do not implement fmt::Display by default

    // This struct cannot be printed since it does not implement fmt::Display not fmt::Debug
    #[allow(dead_code)]
    struct UnPrintable(i32);

    // The derive macro automatically creates the necessary implementation to make this printable with std::Debug
    // To format print with std::Debug we use '?' after the ':' like this {:?}
    #[derive(Debug)]
    struct DebugPrintable(i32);

    // Normal types alreaady have std::Debug implemented so we can format them like this by default
    println!("Months in a year {:?}", 12);
    println!("{0:?} {1:?} is the {actor:?}", "Patrick", "Bateman", actor="actor's");

    println!("the {:?} is now printable", DebugPrintable(47));
    // The problem with this macro is we don't have control of how the variable prints
    // what if we just want the number?

    #[derive(Debug)]
    struct Person<'a> {
        name: &'a str,
        age: u8
    }

    let name = "John";
    let age = 73;
    let john = Person { name, age };

    println!("{:#?}", john);

    // if we want to customize the output of our types we need to use fmt::Display for that we import std::fmt
    use std::fmt;

    // Define a struct on which to implement Display
    struct MyVar(i32);

    // To use the formatter we need to manually implement Display
    impl fmt::Display for MyVar {
        // This trait requires this EXACT signature
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "({})", self.0)
        }
    }

    println!("{}", MyVar(97));

    // TODO: Read 1.2.2 && 1.2.2.1 && 1.2.3
}
