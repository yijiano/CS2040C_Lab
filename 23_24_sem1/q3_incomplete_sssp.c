void Graph::BF(int source) {
    int V = _nv;
    int E = _ne;
    int* dist = new int[_nv];
    bool changed = false;
    // Step 1: Initialize distances from src to all other
// vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = 100000000;
    dist[source] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = _edges[j].v1;
            int v = _edges[j].v2;
            int weight =_edges[j].weight;
            if (dist[u] != 100000000
                && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                changed = true;
            }
           
        }
        if (changed) {
            for (int i = 0; i < _nv; ++i) {
                if (i == _nv - 1) {
                    cout << dist[i];
                    break;
                }
                cout << dist[i] << ",";
            }
            cout << endl;
            changed = false;
        }
       
    }
  

    
    for (int i = 0; i < E; i++) {
        int u = _edges[i].v1;
        int v = _edges[i].v2;
        int weight = _edges[i].weight;
        if (dist[u] != 100000000
            && dist[u] + weight < dist[v]) {
            cout << "Negative Cycle!";
            return; // If negative cycle is detected, simply
            // return
        }
    }
 
}