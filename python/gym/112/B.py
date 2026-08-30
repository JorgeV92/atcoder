import sys

input = sys.stdin.readline

def main():
    B, C = map(int, input().split())
    def get_interval(cost):
        if cost == 0:
            return B, B
        n = cost // 2
        if cost % 2 == 1:
            return -B - n, -B +n 
        else:
            return B-n, B+n-1 
    l1, r1 = get_interval(C)
    l2, r2 = get_interval(C-1)
    sz1 = r1 - l1 + 1
    sz2 = r2 - l2 + 1
    union = max(0, min(r1, r2) - max(l1, l2) + 1)
    ans = sz1 + sz2 - union
    print(ans)

if __name__ == '__main__':
    main()