#!/usr/bin/env python3

import sys
import getopt


def main(argv):
    in_filename = ""
    out_filename = ""
    try:
        opts, args = getopt.getopt(argv, "hi:o:")
    except getopt.GetoptError:
        print('Usage: -i <input file> -o <output file>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print('Usage: -i <input file> -o <output file>')
            sys.exit()
        elif opt in "-i":
            in_filename = arg.strip()
        elif opt in "-o":
            out_filename = arg.strip()

    print('Input file is :', in_filename)
    print('Output file is :', out_filename)

    if in_filename == "" or out_filename == "":
        print('Usage: -i <input file> -o <output file>')
        sys.exit()

    in_file = open(in_filename, 'r')
    out_file = open(out_filename, 'w')

    my_const_array = [1.1, 1.2, 1.3]

    for line in in_file:
        line = line.replace("@array_size@", str(len(my_const_array)))
        line = line.replace("@array_data@", str(my_const_array)[1:-1])
        out_file.write(line)


if __name__ == "__main__":
    main(sys.argv[1:])
