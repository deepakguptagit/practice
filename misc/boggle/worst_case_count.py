import math

def new_matrix(n, m):
  matrix = []
  for i in range(n):
    row = []
    for j in range(m):
      row.append(0)
    matrix.append(row)
  return matrix

#Take input and typecast
n, m, k = (raw_input("")).split(" ")
n = int(n)
m = int(m)
k = int(k)

# Initialize count matrix. Two extra rows and columns as sentinels
current = new_matrix(n+2, m+2)
for i in range(1, n+1):
  for j in range(1, m+1):
    current[i][j] = 1

# Iterate k-1 times
for iter in range(1, k):
  prev = current
  current = new_matrix(n+2, m+2)
  for i in range(1, n + 1):
    for j in range(1, m + 1):
      for dir1 in [0, 1, -1]:
        for dir2 in [0, 1, -1]:
          if dir1 == 0 and dir2 == 0:
            continue
          current[i][j] += prev[i + dir1][j + dir2]

print current[n][m]
print int(math.log(current[n][m], 10)) + 1
