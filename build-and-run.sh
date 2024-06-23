set -e

# if first argument is not provided, build and runs the latest edited file.
target=${1:-$(find . -type f -name "*.cpp" -exec stat --format '%Y :%y %n' "{}" \; | sort -nr | cut -d' ' -f5- | head -n 1)}

echo "Building $target"
g++ -o output -O3 $target
echo "Running:"
./output > output.txt
echo "Output:"
cat output.txt
rm output output.txt
