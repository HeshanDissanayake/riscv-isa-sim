#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_STATES 10
#define REG_FILE_SIZE 32  // Example size, adjust according to your needs

// Structure to store the state
typedef struct {
    uint64_t pc;
    uint64_t reg_file[REG_FILE_SIZE];
} State;

int main() {
    State state_buffer[MAX_STATES];
    int index = 0;
    int total_states = 0;
    char *filename = "state_data.bin";

    // Example loop condition, modify according to your use case
    for(int i =0; i<20; i++) {
        // Simulate fetching data (replace with actual data fetching)
        uint64_t pc = i;
        uint64_t reg_file[REG_FILE_SIZE];
        // Fetch the current reg_file state (replace with actual fetching)
        for (int j = 0; j < REG_FILE_SIZE; j++) {
            reg_file[j] = j+i;
        }

        // Store the current state in the circular buffer
        state_buffer[index].pc = pc;
        memcpy(state_buffer[index].reg_file, reg_file, sizeof(reg_file));

        // Update index for circular buffer
        index = (index + 1) % MAX_STATES;

        // Track total states (up to MAX_STATES)
        if (total_states < MAX_STATES) {
            total_states++;
        }

        
    }

    // Write the data to a binary file from newest to oldest
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Write the states from the newest to the oldest
    for (int i = total_states; i >= 0 ; i--) {
        int write_index = (index - i + MAX_STATES) % MAX_STATES;
        fwrite(&state_buffer[write_index], sizeof(State), 1, file);
    }

    fclose(file);
    printf("Data saved to %s\n", filename);

    return 0;
}
