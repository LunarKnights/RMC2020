// Sachin
// Feb 10, 2020
// Gamepad Dashboard

const gmpWidth = 600;
const gmpHeight = gmpWidth * .5;

const abxycorrds = [[0, 1], [1, 0], [-1, 0], [0, -1]];
const abxylabels = [['A', 'green'], ['B', 'red'], ['X', 'blue'], ['Y', 'yellow']];
const dpadcorrds = [[0, -1], [0, 1], [-1, 0], [1, 0]];
const bumpercoords = [[.2, -1], [.8, 1]];

const Joystick = props => {
	const outer = e('circle', {
		cx: props.x,
		cy: props.y,
		r: gmpWidth * .1,
		stroke: "#141414",
		strokeWidth: "1",
		fill: "#141414"
	});

	const inner = e('circle', {
		cx: props.x,
		cy: props.y,
		r: gmpWidth * .05,
		stroke: "#141414",
		strokeWidth: "1px",
		fill: "#4C6380"
	});

	return e('g', {
		id: props.id
	}, outer, inner);
}

const Button = props => {
	const base = e('circle', {
		cx: props.x,
		cy: props.y,
		r: gmpWidth * .04,
		stroke: "#141414",
		strokeWidth: "1px",
		fill: props.color,
		id: props.id
	});

	const text = e('text', {
		x: props.x,
		y: props.y,
		textAnchor: 'middle',
		fontSize: '20px',
		dy: '.3em'
	}, props.label);

	return e('g', null, base, text);
}

const Bumper = props => {
	const width = gmpWidth * .15 / 2
	const height = gmpHeight * 0.05 / 2
	const btn = e('rect', {
		x: props.x - width,
		y: props.y - height,
		width: width * 2,
		height: height * 2,
		fill: '#4C6380',
		strokeWidth: '1px',
		stroke: '#141414',
		rx: '8',
		transform: `rotate(${props.dir * 5} ${props.x} ${props.y})`,
		id: props.id
	});
	return e('g', null, btn);
}

const Arrow = props => {
	const dx = props.x2 - props.x1;
	const dy = props.y2 - props.y1;
	const len = Math.sqrt(dx*dx + dy*dy);

	const angle = Math.atan2(dy, dx) * 180 / Math.PI;

	const arrowheadLength = 20;
	const arrowheadWidth = 40;
	const lineWidth = 20;
	const dW = arrowheadWidth - lineWidth;

	const d = ['M', 0, -lineWidth/2,
				'h', len - arrowheadLength,
				'v', -dW / 2,
				'L', len, 0,
				'L', len - arrowheadLength, arrowheadWidth / 2,
				'v', -dW / 2,
				'H', 0,
				'Z'];
	const path = e('path', {
		d: d.join(' '),
		transform: `translate(${props.x1},${props.y1}) rotate(${angle})`,
		id: props.id
	});

	return e('g', null, path);
}

const Gamepad = props => {
	const background = e("rect", {
		width: '100%',
		height: '100%',
		fill: '#D6D4DC',
		rx: '30'
	});

	const joy1 = e(Joystick, {
		x: gmpWidth * .25,
		y: gmpHeight / 3,
		id: 'jl'
	});
	const joy2 = e(Joystick, {
		x: gmpWidth * .7,
		y: gmpHeight * .7,
		id: 'jr'
	});

	const abxy = abxycorrds.map((x, i) => e(Button, {
		x: gmpWidth * (.85 + (x[0] * 0.08)),
		y: gmpHeight * (.33 + (x[1] * 0.12)),
		color: abxylabels[i][1],
		label: abxylabels[i][0],
		id: i + 6
	}));

	const bumpers = bumpercoords.map((x, i) => e(Bumper, {
		x: gmpWidth * x[0],
		y: gmpHeight * 0.07,
		dir: x[1],
		id: i + 15
	}));

	const dpad = dpadcorrds.map((x, i) => e(Arrow, {
		x1: gmpWidth * .4,
		y1: gmpHeight * .7,
		x2: gmpWidth * (.4 + (x[0] * 0.08)),
		y2: gmpHeight * (.7 + (x[1] * 0.16)),
		id: i + 17
	}));

	const svg = e('svg', {
			width: gmpWidth,
			height:  gmpHeight,
		}, background, joy1, joy2, ...abxy, ...bumpers, ...dpad);

	return svg;
}

run = _ => ReactDOM.render(e(Gamepad), document.getElementById('root'));