def solve(A, B):
    mod = 1000000007
    ans = 0

    l = 0
    r = len(A) - 1

    while l < len(A) and r >= 0:
        if 1 * A[l] * A[r] >= B:
            r -= 1
        else:
            ans = (ans % mod + (r + 1) % mod) % mod
            l += 1
    return int(ans % mod)

# Example usage:
A = [1, 2, 3, 4, 5]
B = 10
result = solve(A, B)
print("Result:", result)
