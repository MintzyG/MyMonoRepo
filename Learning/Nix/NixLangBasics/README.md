To start please enable nix-command in your nix.conf or configuration.nix
A nix file can only hold a single expression
that may be:

1: a number:
42

2: a string:
"Hello"

3: a boolean
true
false

4: lists:
where list elements are space separated
[ 1 2 3 ];

5: atribute sets
where atribute sets work very similar to json
{
  name = "value";
}

6: Multiline text
text = ''
  text that can be
  written multiline
'';

6: let bindings:
you can look at let bindings as a way to create variables

let
  myNumber = 42
in
  myNumber

this can be viewed like the following

let
  These_bindings = 1;
  That_exist_here = 2;
  exist_in_'in' = 3;
  we_can_have_as_many_bindings_as_we_want = 4;
in
  here is where you can use your bindings
  we can do stuff like arithmetic with them
  These_bindings + That_exist_here
  look at letBindings.nix for examples

Try evaluating the files in this folder with 
