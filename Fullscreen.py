from PIL import ImageGrab
from PIL import Image
import serial
import os
import time

# Serial port settings
ser = serial.Serial("COM15", 229376, timeout=1)
if ser.is_open:
    print("Serial port connection successful")
else:
    print("Serial port connection failed")
    exit()

# Screenshot parameters
screenshot_interval = 30  # Screenshot interval (1 screenshot per second)
screenshot_resolution = (128, 64)  # Screenshot resolution (128x64)

# Folder settings
output_dir = "./output_bin/"

# Limit the number of files sent per second
send_rate_limit = 30

# Waiting time between sending files (per second)
send_interval = 1 / send_rate_limit

def capture_and_send_screen():
    try:
        while True:
            # Capture the screen screenshot
            screen = ImageGrab.grab()
            screen = screen.resize(screenshot_resolution)

            # Convert to black and white image (1-bit pixel, inverted code)
            screen = screen.convert("1")

            # Get the width and height of the image
            width, height = screen.size

            # Create a byte array to store the binary data
            binary_data = bytearray()

            # Reverse mode, take 8 points from the first row to the right as one byte
            for y in range(0, height, 8):
                for x in range(width):
                    byte = 0
                    for i in range(8):
                        if y + i < height and screen.getpixel((x, y + i)):
                            # Set the corresponding bit to 1
                            byte |= (1 << i)
                    # Add byte data to binary data
                    binary_data.append(byte)

            # Generate a file name using the timestamp as the file name
            timestamp = int(time.time())
            bin_filename = f"screenshot_{timestamp}.bin"
            bin_file_path = os.path.join(output_dir, bin_filename)

            # Save binary data to binary file
            with open(bin_file_path, "wb") as bin_file:
                bin_file.write(binary_data)

            print(f"Screenshot saved as {bin_filename}, ready to send")

            # Send the file
            with open(bin_file_path, 'rb') as f:
                data = f.read()

            count = ser.write(data)
            print(f"Sent {bin_filename}, total bytes sent: {count}")

            # Wait for a certain period of time after sending each file to limit the sending speed
            #time.sleep(send_interval)

    except KeyboardInterrupt:
        print("Program ended")

if __name__ == '__main__':
    os.makedirs(output_dir, exist_ok=True)
    capture_and_send_screen()
