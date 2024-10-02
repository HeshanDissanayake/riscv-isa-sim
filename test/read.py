import struct

# Constants
REG_FILE_SIZE = 32  # Must match the REG_FILE_SIZE defined in the C code
STATE_FORMAT = f'Q{REG_FILE_SIZE}Q'  # Q means uint64_t, so this formats pc followed by reg_file
STATE_SIZE = struct.calcsize(STATE_FORMAT)  # Calculate the size of each state in bytes

def read_binary_file(filename):
    states = []

    with open(filename, "rb") as file:
        while True:
            # Read a chunk of data corresponding to one state
            data = file.read(STATE_SIZE)
            if not data:
                break  # End of file reached

            # Unpack the data according to the format (one pc followed by reg_file array)
            unpacked_data = struct.unpack(STATE_FORMAT, data)

            # Extract the pc and reg_file separately
            pc = unpacked_data[0]
            reg_file = list(unpacked_data[1:])  # Remaining values are the reg_file

            # Append the state in the order it is read
            states.append((pc, reg_file))

    return states

def print_registers(registers, start=0, end=REG_FILE_SIZE):
    """
    Print a range of registers with their indices in rows of 8.
    """
    for i in range(start, min(end, len(registers))):
        if i % 8 == 0:
            print()  # Print a new line every 8 registers
        print(f"R{i}: {registers[i]:<20}", end=" ")  # Adjust spacing for alignment
    print()  # Ensure the last row ends with a new line

def interactive_mode(states):
    if not states:
        print("No data available.")
        return

    current_index = 0
    start_register = 0
    end_register = REG_FILE_SIZE

    while True:
        print(f"\nCurrent register range: {start_register} to {end_register - 1}")
        user_input = input(f"Enter a PC (or press Enter to cycle through states in order, current PC: {states[current_index][0]})\n"
                           "Or enter a register range in the format start:end (e.g., 0:5): ").strip()

        if user_input == "":
            # If no input is provided, move to the next state in order
            current_index += 1
            if current_index >= len(states):
                print("Reached the end of available states.")
                current_index = 0  # Loop back to the beginning if desired
        elif ":" in user_input:
            # Handle register range input
            try:
                start_register, end_register = map(int, user_input.split(":"))
                if start_register < 0 or end_register > REG_FILE_SIZE or start_register >= end_register:
                    print(f"Invalid range. Please enter a valid range between 0 and {REG_FILE_SIZE - 1}.")
                    start_register, end_register = 0, REG_FILE_SIZE  # Reset to default
            except ValueError:
                print("Invalid format. Please enter the range in the format start:end (e.g., 0:5).")
                start_register, end_register = 0, REG_FILE_SIZE  # Reset to default
        else:
            try:
                # Convert user input to an integer (PC)
                input_pc = int(user_input)
                
                # Search for the first occurrence of the given PC in the states list
                found = False
                for i, (pc, _) in enumerate(states):
                    if pc == input_pc:
                        current_index = i
                        found = True
                        break
                
                if not found:
                    print(f"Invalid PC: {input_pc}. Please enter a valid PC from the data.")
                    continue
            except ValueError:
                print("Invalid input. Please enter a valid PC as an integer.")
                continue

        # Print the current state information
        pc, reg_file = states[current_index]
        print(f"\nPC: {pc}")
        print_registers(reg_file, start_register, end_register)
        print()

def main():
    filename = "state_data.bin"  # Replace with your actual filename
    states = read_binary_file(filename)

    # Start interactive mode
    interactive_mode(states)

if __name__ == "__main__":
    main()
