class Solution:
    def maxDistance(self, moves: str) -> int:
        r = moves.count('R')
        l = moves.count('L')
        u = moves.count('U')
        d = moves.count('D')
        blank = moves.count('_')

        return abs(r - l) + abs(u - d) + blank