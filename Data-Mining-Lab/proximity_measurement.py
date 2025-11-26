import math

x = [1, 3, 5]
y = [2, 4, 6]

#distances
def euclidean(x,y):
    return math.sqrt(sum((a - b)**2 for a, b in zip(x, y)))

def supremum(x, y):
    return max(abs((a - b) for a, b in zip(x, y)))

def manhattan(x, y):
    return sum(abs((a - b) for a, b in zip(x, y)))

#proximity
def cosine(x, y):
    dotprod = sum((a * b) for a, b in zip(x, y))
    mag_x = math.sqrt(sum(a**2 for a in x))
    mag_y = math.sqrt(sum(a**2 for a in y))
    return dotprod/(mag_x*mag_y)

def jaccard(x, y):
    set_x, set_y = set(x), set(y)
    return len(set_x & set_y)/len(set_x | set_y)