let
  makeSecretStripped = { value }: {
    mySecretValue = value;
  };
in
  makeSecretStripped { key = "abcd"; value = 1234; }


