let
  makeSecretInherit = { key, ... }: {
    inherit key;
  };
in
  makeSecretInherit { key = "abcd"; value = 1234; }


