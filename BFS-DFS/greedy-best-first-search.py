h = {
    'Arad': 366,
    'Bucharest': 0,
    'Craiova': 160,
    'Drobeta': 242,
    'Eforie': 161,
    'Fagaras': 176,
    'Giurgiu': 77,
    'Hirsova': 151,
    'Iasi': 226,
    'Lugoj': 244,
    'Mehadia': 241,
    'Neamt': 234,
    'Oradea': 380,
    'Pitesti': 100,
    'Rimnicu Vilcea': 193,
    'Sibiu': 253,
    'Timisoara': 329,
    'Urziceni': 80,
    'Vaslui': 199,
    'Zerind': 374
}

graph = {
    'Arad': {'Zerind':75, 'Sibiu':140, 'Timisoara':118},
    'Zerind': {'Arad':75, 'Oradea':71},
    'Oradea': {'Zerind':71, 'Sibiu':151},
    'Sibiu': {'Arad':140, 'Oradea':151, 'Fagaras':99, 'Rimnicu Vilcea':80},
    'Fagaras': {'Sibiu':99, 'Bucharest':211},
    'Rimnicu Vilcea': {'Sibiu':80, 'Pitesti':97, 'Craiova':146},
    'Pitesti': {'Rimnicu Vilcea':97, 'Craiova':138, 'Bucharest':101},
    'Timisoara': {'Arad':118, 'Lugoj':111},
    'Lugoj': {'Timisoara':111, 'Mehadia':70},
    'Mehadia': {'Lugoj':70, 'Drobeta':75},
    'Drobeta': {'Mehadia':75, 'Craiova':120},
    'Craiova': {'Drobeta':120, 'Rimnicu Vilcea':146, 'Pitesti':138},
    'Bucharest': {'Fagaras':211, 'Pitesti':101, 'Giurgiu':90, 'Urziceni':85},
    'Giurgiu': {'Bucharest':90},
    'Urziceni': {'Bucharest':85, 'Hirsova':98, 'Vaslui':142},
    'Hirsova': {'Urziceni':98, 'Eforie':86},
    'Eforie': {'Hirsova':86},
    'Vaslui': {'Urziceni':142, 'Iasi':92},
    'Iasi': {'Vaslui':92, 'Neamt':87},
    'Neamt': {'Iasi':87}
}

def best_first_search(start, goal):
    open_set = {start: h[start]}
    came_from = {}
    g_score = {city: float('inf') for city in graph.keys()}
    g_score[start] = 0

    while open_set:
        current = min(open_set, key=lambda x: open_set[x])

        if current == goal:
            print(g_score[current])
            return reconstruct_path(came_from, current)
        del open_set[current]

        for neighbor, dist in graph[current].items():
            tentative_g_score = g_score[current] + dist
            if tentative_g_score < g_score[neighbor]:

                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score

                f_score =  h[neighbor]
                open_set[neighbor] = f_score
    return None

def reconstruct_path(came_from, current):
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.insert(0, current)
    return path

path = best_first_search('Arad', 'Bucharest')
print("Path found:", path)
