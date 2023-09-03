def maxBeauty(str, k, ch):
    count = 0
    ans = float('-inf')
    l = 0
    r = 0
    while r < len(str):
        while r < len(str) and str[r] == ch:
            ans = max(ans, r - l + 1)
            r += 1
        while r < len(str) and str[r] != ch and count < k:
            count += 1
            ans = max(ans, r - l + 1)
            r += 1
        while l <= r and r < len(str) and str[r] != ch and count >= k:
            if k == 0:
                l = r + 1
                break
            count -= str[l] != ch
            l += 1
    return ans


n, k = map(int, input().split())
str = input()
x = maxBeauty(str, k, 'a')
y = maxBeauty(str, k, 'b')
print(max(x, y))
#
