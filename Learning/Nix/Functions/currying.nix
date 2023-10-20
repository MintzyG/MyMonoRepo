let
    greet = greeting: name: "${greeting}, ${name}!";
in
    greet "Howdy" "Planet"
