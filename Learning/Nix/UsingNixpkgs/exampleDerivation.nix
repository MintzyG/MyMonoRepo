let
    pkgs = import <nixpkgs> {};
in
    pkgs.stdenv.mkDerivation {
        name = "my-mkderivation";
        src = ./.;
        installPhase = ''
            echo Test > $out
        '';
    }
