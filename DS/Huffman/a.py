import heapq

with open("huffman.in", "r") as fin:
    n = int(fin.readline())
    freq = list(map(int, fin.readline().split()))

heapq.heapify(freq)
result = 0

while len(freq) > 1:
    a = heapq.heappop(freq)
    b = heapq.heappop(freq)
    combined = a + b
    result += combined
    heapq.heappush(freq, combined)

with open("huffman.out", "w") as fout:
    fout.write(str(result) + "\n")
