from itertools import permutations

def travelling_salesman_brute_force(graph):
    n = len(graph) 
    cities = list(range(n))
    
    min_path = None
    min_cost = float('inf') 

    for perm in permutations(cities[1:]):
        current_path = [0] + list(perm) + [0] 
        current_cost = 0
        
        for i in range(len(current_path) - 1):
            from_city = current_path[i]
            to_city = current_path[i+1]
            current_cost += graph[from_city][to_city]
        
        if current_cost < min_cost:
            min_cost = current_cost
            min_path = current_path
            
    return min_path, min_cost

if __name__ == "__main__":
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],  
        [20, 25, 30, 0]  
    ]
    
    min_path, min_cost = travelling_salesman_brute_force(graph)
    min_path_readable = [city + 1 for city in min_path]
    
    print("Adjacency Matrix (Graph):")
    for row in graph:
        print(row)
    print(f"\nNumber of cities: {len(graph)}")
    print(f"\nOptimal Path: {min_path_readable}")
    print(f"Minimum Cost: {min_cost}")
