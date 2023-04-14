#!/usr/bin/python3

import sys

total_file_size = 0
status_code_count = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0,
}

line_count = 0
for line in sys.stdin:
    try:
        _, _, _, status_code_str, file_size_str = line.split()
        status_code = int(status_code_str)
        file_size = int(file_size_str)
        total_file_size += file_size
        status_code_count[status_code] += 1
        line_count += 1
        if line_count % 10 == 0:
            print(f"Total file size: {total_file_size}")
            for code in sorted(status_code_count.keys()):
                if status_code_count[code] > 0:
                    print(f"{code}: {status_code_count[code]}")
    except KeyboardInterrupt:
        break

print(f"Total file size: {total_file_size}")
for code in sorted(status_code_count.keys()):
    if status_code_count[code] > 0:
        print(f"{code}: {status_code_count[code]}")

