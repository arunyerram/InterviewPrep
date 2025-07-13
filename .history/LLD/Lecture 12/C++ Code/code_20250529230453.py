
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != py:
            self.parent[py] = px

def min_energy_to_install_synchronizers(n, m, energy, connections):
    dsu = DSU(n)
    # Union connected scientists
    for a, b in connections:
        dsu.union(a-1, b-1)  # 0-based indexing

    # Group minimum energy required for each component
    from collections import defaultdict
    component_energy = defaultdict(list)
    for i in range(n):
        root = dsu.find(i)
        component_energy[root].append(energy[i])
    
    # For each component, take min energy
    total_energy = 0
    for e_list in component_energy.values():
        total_energy += min(e_list)
    return total_energy

# ---- Input/Output Handling ----
if __name__ == "__main__":
    n, m = map(int, input().split())
    energy = list(map(int, input().split()))
    connections = []
    for _ in range(m):
        a, b = map(int, input().split())
        connections.append((a, b))
    print(min_energy_to_install_synchronizers(n, m, energy, connections))

