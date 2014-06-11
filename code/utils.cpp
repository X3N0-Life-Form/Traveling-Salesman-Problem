#include "utils.h"

void insert(int* target_array, int* source_array, int size, int origin, int target) {
    // if this is a stupid request
    if (origin == target || target == origin + 1) {
        ARRAY_COPY(target_array, source_array, size);
        return;
    }
    
    // if it is a sensible request
    int t_i = 0;
    int s_i = 0;
    for (int i = 0; i < size; i++) {
        if (s_i == target) {
            target_array[t_i] = source_array[origin];
            t_i = (t_i + 1) % size;
            target_array[t_i] = source_array[target];
        } else if (s_i == origin) {
            s_i = (s_i + 1) % size;
            target_array[t_i] = source_array[s_i];
        } else {
            target_array[t_i] = source_array[s_i];
        }
        t_i++;
        s_i++;
        if (t_i == size)
            t_i = 0;
        if (s_i == size)
            s_i = 0;
    }
}

void reverse(int* target_array, int*source_array, int size, int left, int right) {
    if (left == right) {
        ARRAY_COPY(target_array, source_array, size);
    } else if (left < right) {
        for (int i = 0; i < left; i++) {
            target_array[i] = source_array[i];
        }
        for (int i = right + 1; i < size; i++) {
            target_array[i] = source_array[i];
        }
        // reverse!
        for (int i = 0; i <= (right - left) / 2; i++) {
            target_array[left + i]  = source_array[right - i];
            target_array[right - i] = source_array[left + i];
        }
    } else {
        for (int i = right + 1; i < left; i++) {
            target_array[i] = source_array[i];
        }
        // reverse!
        int r_i = right;
        int l_i = left;
        int range = size - left + right;
        for (int i = 0; i < (range / 2) + 1; i++) {
            target_array[l_i] = source_array[r_i];
            target_array[r_i] = source_array[l_i];
            
            r_i--;
            l_i++;
            if (r_i < 0)
                r_i = size - 1;
            if (l_i == size)
                l_i = 0;
        }
    }
}

int getPairDistance(const std::pair<int, int>& pair, int dimension) {
    int distance = pair.second - pair.first;
    // if we go all the way around
    if (distance < 0) {
        distance = dimension - pair.second + pair.first;
    }
    return distance;
}
