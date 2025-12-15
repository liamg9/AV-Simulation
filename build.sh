cd ~/Desktop/AV-Simulation
rm -rf sim/build
mkdir -p sim/build
cd sim/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
