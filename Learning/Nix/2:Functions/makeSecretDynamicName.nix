let
  makeSecretDynamicName = { key, value }: {
    ${key} = value;
  };
in
  makeSecretDynamicName { key = "abcd"; value = 1234; }


