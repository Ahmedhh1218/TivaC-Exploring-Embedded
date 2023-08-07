import serial
import time

# Configure the serial port (adjust the port name and baud rate accordingly)
ser = serial.Serial('COM7', baudrate=115200, timeout=1)

def send_command(command):
    ser.write(command.encode())

# Open the serial port
ser.open()

while True:
    key = input("Enter a command (R, G, B, W): ")
    if key in ['R', 'G', 'B', 'W', 'r', 'g', 'b', 'w']:
        send_command(key)
        print(f"Command sent: {key}")
    else:
        print("Invalid command. Please enter R, G, B, or W.")

# Close the serial port when done
ser.close()
