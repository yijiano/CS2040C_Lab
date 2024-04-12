void Graph::BF(int source) {
    //printGraph();
    int* dists = new int[_nv];
    int* temp = new int[_nv];

    for (int i = 0; i < _nv; i++) {
        dists[i] = INFINITY_WEIGHT;
    }

    dists[source] = 0;
    for (int i = 0; i < _nv+1; i++) {
        bool relaxed = false;
        for (int j = 0; j < _ne; j++) {
            if (dists[_edges[j].v1] + _edges[j].weight < dists[_edges[j].v2]) {
                dists[_edges[j].v2] = dists[_edges[j].v1] + _edges[j].weight;
                relaxed = true;
            }
        }
        if (!relaxed) {
            break;
        }
        for (int j = 0; j < _nv -1; j++) {
            cout << dists[j] << ",";
        }
        cout << dists[_nv - 1] << endl;
        if (i == _nv - 1) {
            int* temp = dists;
        }
        if (i == _nv) {
            for (int j = 0; j < _nv; j++) {
                if (temp[j] != dists[j]) {
                    cout << NEGATIVECYCLESTRING << endl;
                    break;
                }
            }
        }

        
    }
 
}