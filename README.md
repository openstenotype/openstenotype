[![Join the chat at https://gitter.im/opensteno/chat](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/opensteno/chat?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
# Openstenotype
A free and open steno software for GNU/Linux. It will change the keyboard behaviour so that instead of pushing keys
in sequence to produce a word letter by letter you hold down multiple keys at once to produce whole words and sentences.

To use with qwertz layout change [WindowSystemDriver.cpp Line 13](https://github.com/opensteno/opensteno/blob/master/source/WindowSystemDriver.cpp#L13) from ```strokeKeyMap = keyMapFactory.getNeoKeyMap(stroke);``` to ```strokeKeyMap = keyMapFactory.getQwertzKeyMap(stroke); ```

Compile with
```cmake ./; make; make run;```

To exit opensteno you have to stroke KWR-RBG.
