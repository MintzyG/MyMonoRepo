{pkgs, ...}:

pkgs.stdenv.mkDerivation {
    name = "My_Derivation";
    src = ./.;
    installPhase = ''
      echo HelloMkDerivation > $out
    '';
}
