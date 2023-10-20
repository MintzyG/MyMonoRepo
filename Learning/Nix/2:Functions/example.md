Lets learn functions
in nix all functions take 1 argument

let
  greet = name: "Hello, ${name}!";
in
  greet "World"

Lets understand whats happening

first in the 'let' section we create a function just like any other variable
we named it greet, what makes it an actual function is having an input
which we can do by equaling greet to a input name and capping it off with ':'
so now we have a function named greet that takes name as an argument
after the ':' we can specify what tha function does, here it just holds the text
"Hello, ${name}!" with name interpolated in between, we interpolate in nix just like many other languages
we signal a interpolation by using '$' and then give it what to interpolate inside '{}'
here we gave the input variable name, since we are inputing 'World' in the 'in' section
our stored text will be "Hello, World!", you can test it by evaluating function.nix in this folder

DISCLAIMER: 
This will talk of functional programming for here on out, and will probably be very confusing!

What if we want a function that takes in two items?
We can use currying, by having a function that returns another function

let
  greet = greeting: name: "${greeting}, ${name}!";
in
  greet "Howdy" "Planet"

First in the 'let' section we create a function 'greet' that takes a parameter 'greeting' 
That function greet returns a function that we then call with the value 'name'

So:

...
in
  greet "Howdy" ...

returns a function, lets call it returnFunc, for easier understanding we can now replace the code

...
in
  returnFunc "Planet"

Now we can see that the returned function takes the parameter "Planet"
and the final return value after currying in the closure is "Howdy, Planet!"


Now that we have functions, what can we do with them?
Lets mess around with functions and atribute sets

let
  makeSecret = secret: {
    mySecretValue = secret;
  };
in
  makeSecret "abcd"

in this snippet we have a function 'makeSecret' that takes in a parameter 'secret' and returns an atribute set
this should be easy to follow, so what if I want to pass in multiple values to a function, but don't want to curry it
simple! we can use atribute sets

let
  makeSecretMultiple = secret: {
    mySecretValue = secret;
  };
in
  makeSecretMultiple { key = "my_secret"; value = "super_secret"; }

even tho we are not using both values, we are passing them both to the function, you can see this by evaluating it
but now lets say we want to make 'mySecretValue' be equal to something thats inside the atribute set, not the set itself
nix provides a convenience for you which is de-structure the atribute set in the argument itself, so you can rip out just what you want from inside 
the atribute set you passed in as a parameter

let
  makeSecretDeStructure = { key, value }: {
    mySecretValue = value;
  };
in
  makeSecretDeStructure { key = "abcd"; value = 1234; }

Now if you evaluate the file you will see that 'mySecretValue' holds '1234' instead of the entirety of the atribute set
We can also specify just the atributes we want from an atribute set, so in the above case, since we only want value we could do:

let
  makeSecretStripped = { value }: {
    mySecretValue = value;
  };
in
  makeSecretStripped { key = "abcd"; value = 1234; }

However this here will error out since we only stripped out 'value' from the atribute set but we are passing more than just value to the function
because inside the atribute set we are passing we have 'value' and 'key'
evaluate this file with the argument '--show-trace' to see the error yourself
this is great to restric data that you pass to a function, but sometimes you will want to allow more things to pass that you dont care about
you can do this with the '...' notation inside the de-structure

let
  makeSecretDots = { value, ... }: {
    mySecretValue = value;
  };
in
  makeSecretDots { key = "abcd"; value = 1234; }

if you evaluate this you can see it succeeds

In atribute sets we can also dinamically name variables, just like with interpolating in strings
so lets make 'mySecretValue' name be dynamic and have the value of 'key'  

let
  makeSecretDynamicName = { key, value }: {
    ${key} = value;
  };
in
  makeSecretDynamicName { key = "abcd"; value = 1234; }

if you evaluate this file you'll see that "abcd" has value 1234

And finally what if I just want to pass my value key from this atribute set to belong to the one inside the function?
this could be done like this:

key = key;

However this is a bit convoluted and can be confusing so we can do this instead: 

let
  makeSecretInherit = { key, ... }: {
    inherit key;
  };
in
  makeSecretInherit { key = "abcd"; value = 1234; }

evaluate this to see that we "gave" 'key' to the function atribute set



