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