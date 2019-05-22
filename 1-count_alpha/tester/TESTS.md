# Subject tests
## Test 1
```
./a.out abbcc | cat -e
1a, 2b, 2c$
```
## Test 2
```
./a.out "abbcc" | cat -e
1a, 2b, 2c$
```
## Test 3
```
./a.out "abbcc" "dddeef" | cat -e
$
```
## Test 4
```
./a.out "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
```
## Test 5
```
./a.out "" | cat -e
$
```

# Trace tests
## Test 1
```
./a.out | cat -e
$
```
## Test 2
```
./a.out "ZmlCza6o" "07M6" "FQqKBe1mAxvXkhi" "L4D" "UOji3Bnq" "5pjq4fiCc" "a1LP" "ORmal" "oREZeG4uBI" "uvMjy2o7Bc" "06QFLrA4R7mH1jqW2" "JUTHYNXricIsS6" "roJRwETHl" "vlQ" "8nZhc6JR" | cat -e
$
```
## Test 3
```
./a.out "zUBMNgeEKAF0dH8j" | cat -e
1z, 1u, 1b, 1m, 1n, 1g, 2e, 1k, 1a, 1f, 1d, 1h, 1j$
```
## Test 4
```
./a.out "evuVx8lUKogjDCnAS" | cat -e
1e, 2v, 2u, 1x, 1l, 1k, 1o, 1g, 1j, 1d, 1c, 1n, 1a, 1s$
```
## Test 5
```
./a.out "IieMrls1Em3" | cat -e
2i, 2e, 2m, 1r, 1l, 1s$
```
## Test 6
```
./a.out "FyrsZYGjXNB" | cat -e
1f, 2y, 1r, 1s, 1z, 1g, 1j, 1x, 1n, 1b$
```
## Test 7
```
./a.out "pMdHyTj" | cat -e
1p, 1m, 1d, 1h, 1y, 1t, 1j$
```
## Test 8
```
./a.out "D36FxNAihtTumGd" | cat -e
2d, 1f, 1x, 1n, 1a, 1i, 1h, 2t, 1u, 1m, 1g$
```
## Test 9
```
./a.out "3ifIB1S7dR0c8n4O" | cat -e
2i, 1f, 1b, 1s, 1d, 1r, 1c, 1n, 1o$
```
## Test 10
```
./a.out "fvxnkyl" | cat -e
1f, 1v, 1x, 1n, 1k, 1y, 1l$
```
## Test 11
```
./a.out "PEGzyaV58wnF IDuakiW4tj8TFYByK 41B2lYtAJLNVD97Qu IRfrSid17pVcwv PLN axRUfdbnhG0ol" | cat -e
3p, 1e, 2g, 1z, 4y, 4a, 4v, 3w, 4n, 4f, 4i, 4d, 3u, 2k, 3t, 2j, 3b, 4l, 1q, 3r, 1s, 1c, 1x, 1h, 1o$
```
## Test 12
```
./a.out "uElqcKdOU9gV7eDAL Ar7nGKVh hx134SR 9nNBVA0JY7yRc1 ImBu971sG LK3RWquvi S0aBLx32 qvtgC" | cat -e
4u, 2e, 4l, 3q, 3c, 3k, 2d, 1o, 4g, 5v, 4a, 4r, 3n, 2h, 2x, 3s, 3b, 1j, 2y, 2i, 1m, 1w, 1t$
```
## Test 13
```
./a.out "9C8q QeNRw3tm uLqy KNLT4vY9 Qm9R zF5Dy0QCtS Se5yMrEn 2flJm qVTiCZ65KFaUQOJt KmNdQY9knbS" | cat -e
3c, 8q, 3e, 5n, 3r, 1w, 5t, 5m, 2u, 3l, 5y, 4k, 2v, 2z, 3f, 2d, 3s, 2j, 1i, 1a, 1o, 1b$
```
## Test 14
```
./a.out "RC5pr4 cen09TU4NQVlAphDt RpFlQL qARBlL0tcZfH WNMLBeJZFQzKvO XA5ZHpFTxbryah r5G 7u48ngdL tys84AnWIBvgzCKVP ZbFDWiYq ghp2b5Rtzo 4r3Q9sNOS8mbEkva pEYQliyS86JrF NXoWV1zgSc PCi05DS1R9XlOT TUX1ltP8 nG15y" | cat -e
10r, 6c, 9p, 4e, 8n, 9t, 3u, 7q, 6v, 10l, 6a, 5h, 4d, 6f, 7b, 8z, 4w, 2m, 2j, 3k, 5o, 5x, 6y, 6g, 6s, 4i$
```
## Test 15
```
./a.out "WsaOUI0oM cSM qAZ fuE qxn9NSsR6PFDy owj8 hm6lrNiZDXMQIyJfS wrqSBszUeXE y6NPx4qsIt7lC 16i5FZapQg 2o9z4b6MCDqKd8 9kvS4 ArzOLvFRQ6YoThl JB9 D8jWXrCxKFT9 5fQ7Y4whr6FJOoa uobTkM0mXjIv8Q PYFZiwJqTe" | cat -e
6w, 9s, 5a, 9o, 4u, 7i, 7m, 4c, 11q, 7z, 9f, 4e, 7x, 4n, 7r, 4p, 5d, 6y, 7j, 3h, 4l, 4b, 5t, 1g, 4k, 3v$
```
## Test 16
```
./a.out "2KHiPAsmjkBh 8Cc ZixqRXhdrOfE9K5 7KYjiuHBaZE6 fugRzs9vy xv1cVXfPaDmNQsht UlmNZRyHbtDF poXb 63cVhRlIn" | cat -e
4k, 7h, 4i, 3p, 3a, 3s, 3m, 2j, 4b, 4c, 4z, 5x, 2q, 5r, 3d, 2o, 4f, 2e, 3y, 3u, 1g, 4v, 3n, 2t, 2l$
```
## Test 17
```
./a.out "Hjnq Mx6sCro jLlsSONrCAPWn UNiaK7fBV 6AT9GVjqI" | cat -e
1h, 3j, 4n, 2q, 1m, 1x, 3s, 2c, 2r, 2o, 2l, 3a, 1p, 1w, 1u, 2i, 1k, 1f, 1b, 2v, 1t, 1g$
```
## Test 18
```
./a.out "mNSnfk DiU3G9g TyA41bBVcF woVA4PkpFduLI IjvEclFAfue 15HWdQvZ6TwAt DLsj5yKOpmPwNhkH UjMna2PiJoT" | cat -e
3m, 4n, 2s, 5f, 4k, 4d, 4i, 4u, 2g, 4t, 2y, 5a, 2b, 4v, 2c, 4w, 3o, 5p, 3l, 4j, 2e, 3h, 1q, 1z$
```
## Test 19
```
./a.out "ifk35REPY4 l8i1tJqK7 LEqyfW0TkoQaCrZDx wTKf y4mHfVjvT 6eTcC RuJHsQt4ZY9Aq oc3Ej OluwB7SVHUtKe1P f1UCv Nxp W57XvzTRid O1Db MKb78NuR hRXoW3Zb1JCx dT3rm5" | cat -e
3i, 5f, 6k, 7r, 5e, 3p, 4y, 3l, 9t, 5j, 5q, 5w, 5o, 2a, 6c, 4z, 4d, 5x, 3m, 4h, 5v, 5u, 2s, 4b, 2n$
```
## Test 20
```
./a.out "C0d9UKG2nfJEs6kIi L39K 2XoUHDeOpkaPWE9 O9SnXEvTg qGbknV7yMCveTJIs RFeZH03UdJAODWxNI UnKJ6 QcMvnu2ohY9Ita O6ScvPkgFIKhfy QL2tqVj 3luKB JUzxleKfF4ykj 1zFQ20 Uj2g" | cat -e
4c, 4d, 8u, 11k, 5g, 6n, 7f, 8j, 7e, 4s, 6i, 4l, 4x, 6o, 4h, 3p, 3a, 2w, 6v, 4t, 5q, 2b, 4y, 2m, 1r, 3z$
```
