set -e

# if first argument is not provided, build and runs the latest edited file.
target=${1:-$(find . -type f -name "*.cpp" -exec stat --format '%Y :%y %n' "{}" \; | sort -nr | cut -d' ' -f5- | head -n 1)}

echo "Building $target"
g++ -o output -O3 -std=c++17 $target
if [ -f "input.txt" ]; then
    ./output < input.txt > output.txt
else
    echo "Running:"
    ./output > output.txt
fi
echo "Output:"
cat output.txt
