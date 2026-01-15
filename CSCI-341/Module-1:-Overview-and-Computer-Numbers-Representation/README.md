# Integer Representation

## self check 1

1. Convert integer binary 1101 0001 to hex

```
(1+4+8) 1
D1
```

2. Convert 8-bit unsigned binary 11001100 to decimal

```
2^7 + 2^6 + 2^3 + 2^2
128+64+8+4=204
```

3. Convert 8-bit unsigned number 0xCD to decimal and binary
4. Convert 65 to hexadecimal
5. Convert 34 to binary
6. What is the largest possible 16-bit unsigned binary number?

## self check 2

1. Convert the 8-bit, 2’s complement 10110101 to decimal

```
MSB is 1, so the number is negative.
invert all bits: 01001010 (sign negation)
add 1: 01001011
convert this positive number to decimal: 2^6+2^3+2^1+2^0= 64+8+2+1=75
apply the negative: -75
```

2. Convert decimal (-1)10 to 9-bit 2’s complement binary

```
111111111
```

3. Convert 8-bit 2’s complement binary 11001101 to decimal and hex

4. What is the largest possible 16-bit signed binary number in 2’s
   complement?

# Floating Point Representation
