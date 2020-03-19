// Sachin
// Feb 15, 2020
// Current Dashboard

const motorNames = ['Front Left', 'Back Left', 'Front Right', 'Back Right']
const labelColors = ['#664477', '#ee1144', '#116699', '#32d312']

class Current extends c
{
	chartRef = React.createRef();

	constructor(props)
	{
		super(props);
		this.state = { chart: null };
	}

	componentDidMount()
	{
		const { data } = this.props;

		const dataset = data.map((x, i) => {
			return {
				label: motorNames[i],
				data: x,
				fill: false,
				borderColor: labelColors[i]
			}
		});

		const myChartRef = this.chartRef.current.getContext('2d');
		const chart = new Chart(myChartRef, {
			type: 'line',
			title: 'Current',
			data: {
				labels: new Array(10).fill(0).map((x,i)=>i),
				datasets: dataset
			},
			options: {
				scales: {
					xAxes: [{
						ticks: {
							display: false
						},
					}],
					yAxes: [{
						ticks: {
							suggestedMax: 15,
							min: 0,
							//stepSize: 5,
						},
					}],
				},
			}
		});

		this.setState({ chart: chart });

		window.addCurrent = data => {
			this.state.chart.data.datasets.forEach((dataset, i) => {
			if (dataset.data.length > 9) dataset.data.shift();
				dataset.data.push(data[i])
			});

			this.state.chart.update(0);
		}
	}

	componentDidUpdate()
	{
		this.state.chart.data.datasets.forEach((dataset, i) => {
			if (dataset.data.length > 9) dataset.data.shift();
			dataset.data.push(this.props.data[i])
		});

		this.state.chart.update(0);
	}

	render()
	{
		return e('canvas', { ref: this.chartRef });
	}
}

run = _ => ReactDOM.render(e(Current, { data: [[0], [0], [0], [0]] }), document.getElementById('root'));
