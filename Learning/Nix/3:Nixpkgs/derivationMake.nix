let
    pkgs = import <nixpkgs> {};
in
    pkgs.stdenv.mkDerivation {
        name = "my_mkDerivation";

        src = ./.;

        installPhase = ''
            echo HelloMkDerivation > $out
        '';
    }
