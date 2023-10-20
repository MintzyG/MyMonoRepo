let
  makeSecretDots = { value, ... }: {
    mySecretValue = value;
  };
in
  makeSecretDots { key = "abcd"; value = 1234; }


