let
  useMyLibrary = import ./greet.nix;
in
  useMyLibrary.greet "My Library"

