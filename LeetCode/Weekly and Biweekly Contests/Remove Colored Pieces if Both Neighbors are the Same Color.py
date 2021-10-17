class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alfa = colors.split('B')
        a = sum(max(0, len(s)-2) for s in alfa)
        beta = colors.split('A')
        b = sum(max(0, len(s)-2) for s in beta)
        return a>b