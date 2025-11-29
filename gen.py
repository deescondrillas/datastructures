#!/usr/bin/env python3
import sys

def generate(n, outfile=None):
    blocks = []
    for i in range(1, n+1):
        a_str = 'a' * i
        block = "\n".join([
            "1",
            a_str,
            "volkswagen",
            "jetta",
            "2005"
        ])
        blocks.append(block)
    content = "\n".join(blocks)  # blank line between blocks, trailing newline
    if outfile:
        with open(outfile, "w", encoding="utf-8") as f:
            f.write(content)
    else:
        print(content, end="")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python gen.py N [output.txt]")
        sys.exit(1)
    n = int(sys.argv[1])
    out = sys.argv[2] if len(sys.argv) >= 3 else None
    generate(n, out)
