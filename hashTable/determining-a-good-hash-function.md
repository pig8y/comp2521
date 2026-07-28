# How to determine whether a hashing function is a good hash
So the ultimate goal of using hash table is to store the key-value pair and we can do insert, delete and lookup easily, and a well spread table significantly assist thses operations. That is, TO DETERMINE WHETHER A HASHING FUNCTION IS GOOD OR NOT, WE SEE IF A HASHING FUNCTION CAN SPREAD KEYS EVENLY, and to know if a function can spread keys evenly, we look at the easeiness of produce collision:

- if the hashing function used up any informations from keys, it can largely prevent collision as these information creates more uniqueness to prevent collision Information including:
        - Order of the character
        - Length of the key
        - What is each character

SUMMARY: 
        If function considered position, order, length etc. => produce more unique index for each key => distribute keys more evenly => less collision => good hashing
        If function considered not much characteristic of these keys => probability of produce repetitive index for different key increase => more collision => bad hashing

