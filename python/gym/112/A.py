import sys 

def main():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        L, R = map(int, input().split())
        D = R - 2* L 
        if D < 0:
            print(0)
        else:
            print((D+1) * (D+2) // 2)

if __name__ == "__main__":
    main()