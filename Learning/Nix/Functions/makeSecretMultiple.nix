let
    makeSecretMultiple = secret: {
        mySecret = secret;
    };
in
    makeSecretMultiple { key = "abcd"; value = 1234; }
