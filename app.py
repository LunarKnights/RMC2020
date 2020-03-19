# Lunar Knights
#
# Sachin Shah
# February 10, 2020
#
# Server script

on_robot = True
try:
	import lkpy
except ImportError:
	on_robot = False

from flask import Flask,render_template, request
from flask_socketio import SocketIO, emit
import json
import random
import sys
import threading

# Create the server and socket instances
app = Flask(__name__)
socketio = SocketIO(app)

def num(): return random.random() * 100

def worker():
	while True:
		if (on_robot): socketio.emit('amps', [lkpy.get_current(i) for i in range(1,5)]) 
		else: socketio.emit('amps', [num(), num(), num(), num()])
		socketio.sleep(0.5)

@socketio.on('connect')
def connect():
	print('Spinning up')
	if (on_robot):
		lkpy.init()
		lkpy.start()
	t = threading.Thread(target=worker)
	t.start()

@socketio.on('disconnect')
def disconnect():
	if (on_robot): lkpy.stop()
	print('Stopped')

# Dashboard
@app.route('/')
def index():
	return render_template('index.html')

@app.route('/amps')
def amps():
	return render_template('current.html')

# Handle post requests
@app.route('/gamepad', methods = ['POST'])
def gamepads():
	d = request.form.to_dict()
	# Emit the data to client
	socketio.emit("data", json.dumps(d), broadcast=True)
	# Take actions for each input
	for key in d:
		if key == '15':
			if d[key] == 1:
				lkpy.stop()
				sys.exit(1)
		else: lkpy.teleop(int(key), float(d[key]))
	return 'g'

if __name__ == '__main__':
	socketio.run(app, debug=True, host='0.0.0.0')
