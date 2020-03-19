# UCF Lunar Knights RMC 2020
The codebase for the UCF Lunar Knights Mining Robot. This contains the code for autonomous and teleop controls as well as a debugging monitor.

## How to Contribute:
### Dependencies
```
pip install npyscreen
pip install flask
pip install flask-socketio
```

### Control Systems Library
Add C++ files: `./add-cpp` and add the source file to the `CMakeLists.txt` file. Alternatively, create a header file in `include/LK` and the corresponding source file in `src`.

To add to the python module edit the `lkpymodule.cpp` in `src`. Add the PyMethod to the `LKPYMethods` array with the python method name and a brief description of the function.

Build the C++ library with `./build-cpp`

Build & install the Python module with `./build-py`

### Dashboard
Run: `python3 app.py`

Add html files to the `templates` folder and javascript & css files to the `static` folder. In `app.py` create a route method to render the appropriate html file.