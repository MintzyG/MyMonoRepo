let
  makeSecretDeStructure = { key, value }: {
    mySecretValue = value;
  };
in
  makeSecretDeStructure { key = "abcd"; value = 1234; }

