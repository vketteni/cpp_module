#!/bin/bash

# Script to generate large test inputs for PmergeMe

# Default values
SIZE=3000
MIN=1
MAX=100000
OUTPUT_FILE=""
PROGRAM="./PmergeMe"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

usage() {
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "Generate and test large inputs for PmergeMe program"
    echo ""
    echo "Options:"
    echo "  -s, --size SIZE      Number of elements to generate (default: 3000)"
    echo "  -m, --min MIN        Minimum value (default: 1)"
    echo "  -M, --max MAX        Maximum value (default: 100000)"
    echo "  -o, --output FILE    Save generated numbers to file"
    echo "  -p, --program PATH   Path to PmergeMe program (default: ./PmergeMe)"
    echo "  -t, --test-only      Only run test, don't generate new numbers"
    echo "  -g, --generate-only  Only generate numbers, don't run test"
    echo "  -v, --verify         Verify the output is actually sorted"
    echo "  -h, --help           Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                           # Generate 3000 random numbers and test"
    echo "  $0 -s 5000 -v               # Generate 5000 numbers and verify sorting"
    echo "  $0 -s 1000 -o test.txt      # Save 1000 numbers to file"
    echo "  $0 -t -o test.txt            # Test using numbers from file"
}

generate_numbers() {
    if command -v shuf >/dev/null 2>&1; then
        # Use shuf (Linux)
        shuf -i $MIN-$MAX -n $SIZE
    elif command -v jot >/dev/null 2>&1; then
        # Use jot (macOS/BSD)
        jot -r $SIZE $MIN $MAX
    else
        # Fallback: use awk with random
        awk -v size=$SIZE -v min=$MIN -v max=$MAX 'BEGIN {
            srand();
            for(i=1; i<=size; i++) {
                print int(rand() * (max - min + 1)) + min
            }
        }'
    fi
}

verify_sorted() {
    local input="$1"
    echo "$input" | awk '
    /^After:/ {
        for(i=2; i<=NF; i++) {
            if(i > 2 && $i < $(i-1)) {
                print "❌ NOT SORTED: " $(i-1) " > " $i " at position " (i-1)
                exit 1
            }
        }
        print "✅ VERIFIED: Output is correctly sorted"
        exit 0
    }'
}

run_test() {
    local numbers="$1"
    local count=$(echo "$numbers" | wc -w)
    
    echo -e "${BLUE}Testing with $count numbers...${NC}"
    echo -e "${YELLOW}Running: $PROGRAM $numbers${NC}"
    echo ""
    
    # Run the program and capture output
    local output
    if output=$($PROGRAM $numbers 2>&1); then
        echo "$output"
        
        if [ "$VERIFY" = true ]; then
            echo ""
            echo -e "${YELLOW}Verifying results...${NC}"
            verify_sorted "$output"
        fi
        
        echo ""
        echo -e "${GREEN}✅ Test completed successfully!${NC}"
    else
        echo -e "${RED}❌ Error running program:${NC}"
        echo "$output"
        return 1
    fi
}

# Parse command line arguments
VERIFY=false
TEST_ONLY=false
GENERATE_ONLY=false

while [[ $# -gt 0 ]]; do
    case $1 in
        -s|--size)
            SIZE="$2"
            shift 2
            ;;
        -m|--min)
            MIN="$2"
            shift 2
            ;;
        -M|--max)
            MAX="$2"
            shift 2
            ;;
        -o|--output)
            OUTPUT_FILE="$2"
            shift 2
            ;;
        -p|--program)
            PROGRAM="$2"
            shift 2
            ;;
        -t|--test-only)
            TEST_ONLY=true
            shift
            ;;
        -g|--generate-only)
            GENERATE_ONLY=true
            shift
            ;;
        -v|--verify)
            VERIFY=true
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        *)
            echo "Unknown option $1"
            usage
            exit 1
            ;;
    esac
done

# Validate inputs
if ! [[ "$SIZE" =~ ^[0-9]+$ ]] || [ "$SIZE" -lt 1 ]; then
    echo -e "${RED}Error: Size must be a positive integer${NC}"
    exit 1
fi

if ! [[ "$MIN" =~ ^[0-9]+$ ]] || ! [[ "$MAX" =~ ^[0-9]+$ ]]; then
    echo -e "${RED}Error: Min and Max must be positive integers${NC}"
    exit 1
fi

if [ "$MIN" -ge "$MAX" ]; then
    echo -e "${RED}Error: Min must be less than Max${NC}"
    exit 1
fi

# Main execution
if [ "$TEST_ONLY" = true ]; then
    if [ -z "$OUTPUT_FILE" ] || [ ! -f "$OUTPUT_FILE" ]; then
        echo -e "${RED}Error: For test-only mode, specify existing file with -o${NC}"
        exit 1
    fi
    
    echo -e "${BLUE}Loading numbers from $OUTPUT_FILE...${NC}"
    NUMBERS=$(cat "$OUTPUT_FILE" | tr '\n' ' ')
    run_test "$NUMBERS"
    
elif [ "$GENERATE_ONLY" = true ]; then
    echo -e "${BLUE}Generating $SIZE random numbers between $MIN and $MAX...${NC}"
    NUMBERS=$(generate_numbers | tr '\n' ' ')
    
    if [ -n "$OUTPUT_FILE" ]; then
        echo "$NUMBERS" > "$OUTPUT_FILE"
        echo -e "${GREEN}Numbers saved to $OUTPUT_FILE${NC}"
    else
        echo "$NUMBERS"
    fi
    
else
    # Default: generate and test
    echo -e "${BLUE}Generating $SIZE random numbers between $MIN and $MAX...${NC}"
    NUMBERS=$(generate_numbers | tr '\n' ' ')
    
    if [ -n "$OUTPUT_FILE" ]; then
        echo "$NUMBERS" > "$OUTPUT_FILE"
        echo -e "${GREEN}Numbers saved to $OUTPUT_FILE${NC}"
        echo ""
    fi
    
    run_test "$NUMBERS"
fi