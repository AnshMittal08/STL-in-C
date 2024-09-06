#include <stdio.h>
#include "map.h"

int main() {
    HashMap* map = createHashMap();

    // Insert key-value pairs
    put(map, "first", 42);
    put(map, "second", 100);

    // Retrieve values
    printf("Value for 'first': %d\n", get(map, "first"));
    printf("Value for 'second': %d\n", get(map, "second"));

    // Remove a key
    removeKey(map, "first");
    printf("Value for 'first' after removal: %d\n", get(map, "first")); // Should print -1

    // Check if the map is empty
    printf("Is the map empty? %s\n", isEmpty(map) ? "Yes" : "No");

    // Free the map
    freeHashMap(map);

    return 0;
}