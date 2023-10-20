# Now we have most of the basics done
# so lets say we want to do something new, we would have to write lots of helpers for everything like:
# 
# Maps
# Filters
# Etc
#
# And thats where we start talking about nixpkgs
# because Nixpkgs is not a repository for just conventional packages, it also
# includes libraries, and in order to learn how to use them we need to learn how to
# import other nix files, so lets import some stuff
#
# Lets have a file that has the values, and a file that has the function
# We will do this with the greet function we saw previously
# So we have two files, the first contains just an atribute set with the greet function
#
# {
#   greet = name: "Hello, ${name}!"
# }
#
# And in the other file we will import this file so we can use the function
#
# let
#   myLibrary = import ./greet.nix;
# in
#   myLibrary
# 
# Since we imported greet.nix when evaluated this file should show the atribute set contained in that file
#
# DISCLAIMER: remember since nix is a functional language we may have complex topics
# and we get what we expected, an atribute set where greet is a LAMBDA function
#
#
# cool, that means we sucessfully imported that file and it is an atribute set full of functions
# to use any specific function inside that atribute set we can use dot notation
#
# let
#   useMyLibrary = import ./greet.nix;
# in
#   useMyLibrary.greet "My Library"
#
# evaluating this we can see it correctly outputs "Hello, My Library!"
#
#
# So now for the fun part
# we can do a similar thing with nix packages
#
# However since we dont have nixpkgs installed locally how do we import it since we can't provide a path?
# simple, nix keeps a environment variable called $NIX_PATH that gives you a path, inside that folder
# we can see what is to be imagined as a bunch of folders with nix files in them, that can be imported without knowing
# their path, so to import nix packages, you would be retrieving the nixpkgs 'folder' from $NIX_PATH
# this method isn't actually used in the nix product/nix/var/nix/profiles/per-user/root/channels/nixos/pkgs/stdenv/generic/make-derivation.nix:303:7ion since it wouldn't be very reproductible, but its great to start learning
#
# this method require a special syntax, that look similar to how you would include a header file in C for example
#
# let
#   pkgs = import <nixpkgs>;
# in
#   pkgs
#
# This is how you import nixpkgs into a nix file, lets evaluate this and see what it prints out
#
# So we can see nixpkgs is just a function, one that expects being called with an atribute set that
# lets you provide some configurations for libraries and packages, but you can provide an empty set for the defaults
#
# let
#   pkgsDefault = import <nixpkgs> {};
# in
#   pkgsDefault
#
# Evaluating this would in theory print out the entirety of nixpkgs, however it is so big it was designed to thro an error if you tried to do that
# But we can evaluate parts of it, lets do it with the libraries, since we want to learn how to use them
#
# let
#   pkgsLib = immport <nixpkgs> {};
# in
#   pkgsLib.lib
#
# Evaluating this we can see we get all libraries inside nixpkgs printing out to console
# we can see it contains lots of stuff, however the best way to explore the outputs is not like this
# the best way is through 'nix repl'
# the nix repl, just like any other repl lets you put in an expression and see its output
# So lets do the same thing but in the repl
#
# first enter the repl by typing 'nix repl' into your shell
# the setup the variable 'pkgs' by doing
#
# NOTE: the repl does not require ';', this is repl specific syntax
# pkgs = import <nixpkgs> {} 
#
# then hit enter, following that, type 'pkgs.lib.' and press tab
# the repl will then list all libraries available
# in this list theres a lot of helpers for a bunch of cases
# nix also has builtins, so libraries already built in to nix
# to check them type 'builtins.' and then press tab in the repl
# here you can find helpers for map, filter, add, etc
#
# so now you how to import nixpkgs into a nix file
# lets say we want to import the librarie 'add'
# we would import nixpkgs in the 'let' binding
# and then use the 'add' library from nixpkgs in the 'in' binding
#
# ...
# in
#   pkgs.lib.add
#
# if you believe me or not, since the beginning, you have learned enough to build your own package
# we will not do this the 'right way' first, we'll do it the simplest possible way by using a builtin function
#
# builtins.derivation {
# }
#
# we cannot call it without arguments or it will give us an error
# so lets pass some arguments
#
# builtins.derivation{
#   name = "my-derivation";
#
#   # specify the systems our package runs in
#   # you can find systems in the repl by
#   # setting a variable for nixpkgs
#   # doing "pkgs.lib.platforms" and hitting enter
#   # to just get the names from these atribute sets do
#   # "builtins.attrNames pkgs.lib.platforms" and hit enter
#   system = "x86_64-linux";
#
#   # program tha we will execute to make our package
#   builder = "/bin/sh";
# 
#   # specify args passed to the builder
#   args = [ "-c" "echo Hello > $out"];
# }
#
# Evaluating this file returns a big atribute set which is the result of our derivation
#
# So we can create our derivation using the comman 'nix-instantiate'
#
# Lets run through the steps of creating our package
# First we make the derivation, which is one step before realizing the package
# we can look at it like the settings for creating said package
#
# Then we instantiate ou derivation, which makes nix produce a derivation file
# which you can peek by opening the output path mentioned in the eval in your text editor after instantiating the derivation
#
# Once we have a derivation file instantiated we can go ahead and realize it
# you do this by using "nix-store --realise" and passing it the path of your derivation
# in this case the result of this derivation will be a file, since we wrote Hello to it, so you can cat the output path of 'nix-store --realise' to see your hello
#
# Using the derivation function directly is very tedious and requires you to rebuild everything
# However the beatuy of nixpkgs, all of the work has already been done for you
# so lets use nixpkgs stuff now
#
# let
#   pkgs = import <nixpkgs> {};
# in
#   pkgs.runCommand "my-derivation" {} '' 
#     echo Hello > $out
#   '';
#
# Lets use nix-build on this file
# You notice nix-build doesn't give you a path, not to worry, it builds a symlink to the file in the working directory
# so here you can 'cat' result
#
# Some packages in nixpkgs are built the way we just did
# but most of them actually use 
#
# pkgs.stdenv.mkDerivation {};
#
# this is way more orchestrated than builtins.derivation, since it works around phases of a build and other stuff
#
# let
#   pkgs = import <nixpkgs> {};
# in
#   pkgs.stdenv.mkDerivation {
#     name = "my_derivation";
#
#     # mkDerivation requires a source of some kind
#     src = ./.;
#
#     installPhase = ''
#       echo HelloMkDerivation > $out
#     '';
#   }
#
# the reason why you wouldn't use build derivation directly is because it requires a lot of setup
# mkDerivation wrap the derivation function to do all of the busy work for you
# most of the time you will reach for mkDerivation or one of the more trivial builders like runCommand
#
