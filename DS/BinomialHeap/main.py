with open("huffman.in") as infile:
    n = int(infile.readline().strip())

orders = []
k = 0
x = n
while x > 0:
    if x & 1:
        orders.append(k)
    x >>= 1
    k += 1

with open("huffman.out", "w") as outfile:
    pass
