template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
   if (N >= M) {
        throw runtime_error("Hash table is full");
    }
    
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            N++;
            return i + 1; 
        }
        if (table[idx] == key) {
            return i + 1; 
        }
    }
    
    throw runtime_error("Could not insert key after probing all positions");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) 
{
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        
        if (!occupied[idx]) {
            return make_pair(false, i + 1);
        }
        
        if (table[idx] == key) {
            return make_pair(true, i + 1);
        }
    }
    
    return make_pair(false, M);
}
