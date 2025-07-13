def min_operations_to_equal(n, p, q, A):
    from collections import defaultdict

    def reduce_and_count(x):
        ops = 0
        while x % p == 0:
            x //= p
            ops += 1
        while x % q == 0:
            x //= q
            ops += 1
        return x, ops

    reduced = []
    total_ops = 0
    for a in A:
        r, ops = reduce_and_count(a)
        reduced.append(r)
        total_ops += ops

    # If all reduced values aren't the same, not possible
    if len(set(reduced)) > 1:
        return -1
    return total_ops

# Input handling
if __name__ == "__main__":
    n, p, q = map(int, input().split())
    A = list(map(int, input().split()))
    print(min_operations_to_equal(n, p, q, A))