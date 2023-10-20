builtins.derivation{
  name = "my-derivation";

  # specify the systems our package runs in
  # you can find systems in the repl by
  # setting a variable for nixpkgs
  # doing "pkgs.lib.platforms" and hitting enter
  # to just get the names from these atribute sets do
  # "builtins.attrNames pkgs.lib.platforms" and hit enter
  system = "x86_64-linux";

  # program tha we will execute to make our package
  builder = "/bin/sh";

  # specify args passed to the builder
  args = [ "-c" "echo Hello > $out"];
}

